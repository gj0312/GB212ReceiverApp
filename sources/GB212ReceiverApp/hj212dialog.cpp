#include "hj212dialog.h"
#include "ui_hj212dialog.h"
#include "gb212.h"
#include <QDebug>
#include "pub.h"
#include "func.h"
#include <QTableWidgetItem>

#pragma execution_character_set("utf-8")

HJ212Dialog::HJ212Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HJ212Dialog)
{
    ui->setupUi(this);

    // QDialog 添加最大化、最小化按钮和关闭按钮，并且要正常显示
    // https://blog.csdn.net/xueyushenzhou/article/details/51291404
    Qt::WindowFlags flags = Qt::Dialog;
    flags |= Qt::WindowMinMaxButtonsHint;
    flags |= Qt::WindowCloseButtonHint;
    setWindowFlags(flags);

    //监听套接字   指定父对象的目的，让其自动回收空间
    tcpServer = new QTcpServer(this);

    // 默认监听端口设置为8099
    ui->lineEditPort->setText("8099");

	// 连接数据库
    dbprocess_.setDBInfo("127.0.0.1", 3306, "root", "1030", "test_hj212_db");
    dbprocess_.connectDB();
    dbprocess_.getDBList();
}

HJ212Dialog::~HJ212Dialog()
{
    delete ui;
}


void HJ212Dialog::on_btnStop_clicked()
{
        if(nullptr == tcpSocket)
        {
            return ;
        }
        //主动和客户端端口断开连接
        tcpSocket->disconnectFromHost();
        tcpSocket->close();

        tcpSocket = nullptr;

        tcpServer->close();

        ui->btnListen->setChecked(true);
        ui->btnStop->setChecked(false);
}

void HJ212Dialog::on_btnListen_clicked()
{
    if (tcpServer != nullptr)
    {
        qint16 port = ui->lineEditPort->text().toInt();
        tcpServer->listen(QHostAddress::Any, port);

        setWindowTitle(tr("Server start at: %1").arg(port));

        connect(tcpServer, SIGNAL(newConnection()), this, SLOT(handleAccept()));
        ui->btnListen->setChecked(false);
        ui->btnStop->setChecked(true);
    }
}

//  处理客户端的连接请求
void HJ212Dialog::handleAccept()
{
    //取出建立好连接的的套接字
    tcpSocket = tcpServer->nextPendingConnection();

    //获取对方的IP和端口
    QString ip = tcpSocket->peerAddress().toString();
    uint16  port = tcpSocket->peerPort();
    QString temp = QString("[%1:%2]:connected successful").arg(ip).arg(port);
    ui->textEditRead->setText(temp);

    /*注意这里的connect的位置，一定在建立好连接后，
     * 不然会出现野指针的错误，前面定义的QTcpSocket  *tcpSocket;
     * 而程序会先从构造函数执行的，还没有执行到定义的QTcpSocket  *tcpSocket指针。
    */
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(handleRecevice()));
}

// 解析客户端上传的报文
void HJ212Dialog::handleRecevice()
{
    //从通信套接字中取出内容
    // 读取数据缓冲区数据
    QByteArray buffArr = tcpSocket->readAll();
    if (!buffArr.isEmpty())
    {
        QString str = ui->textEditRead->toPlainText();
        QString strRecv = QString::fromLocal8Bit(buffArr);
        str += strRecv + "\n";
        // 刷新界面显示
        ui->textEditRead->setText(str);
        // ui->textEditRead->append(buffArr);
    }


    String strBody = buffArr.toStdString();

    // parse gb212 format data
    GB212::GB212Array arr;
    GB212::Parser(arr, strBody);
    // 实时，最新，报文
    for (auto& i : arr) {
        if (i.valid()) {
            // 实时数据, 设置回复数据 , 推送
            if (i.is_data()) {
               // 解析处理212数据报文
               qDebug() << "***HJ212-2017 data parser successful!***" << "\n";
               qDebug() << "full data=" << i.full.c_str() << "\n";
               qDebug() << "header=" << i.header.c_str() << "\n";
               qDebug() << "ST=" << i.data.ST.c_str() << "\n";
               qDebug() << "CN=" << i.data.CN.c_str() << "\n";
               qDebug() << "PW=" << i.data.PW.c_str() << "\n";
               qDebug() << "MN=" << i.data.MN.c_str() << "\n";
               qDebug() << "Flag=" << i.data.Flag.c_str() << "\n";
               qDebug() << "CP=" << i.data.CP.c_str() << "\n";
               qDebug() << "QN=" << i.data.QN.c_str() << "\n";

			   // 更新界面上的HJ212报文信息，显示最新接收到的HJ212-2017报文
			   String strQNTime = Math::Date::convertfmt(i.data.QN.substr(0,14).c_str(), "%04d%02d%02d%02d%02d%02d", "%04d年%02d月%02d日 %02d时%02d分%02d秒");
               ui->lineEditQN->setText(QString::fromStdString(strQNTime));
			   ui->lineEditMN->setText(QString::fromStdString(i.data.MN));
			   ui->lineEditCN->setText(QString::fromStdString(i.data.CN));
			   ui->lineEditST->setText(QString::fromStdString(i.data.ST));
			   ui->lineEditFlag->setText(QString::fromStdString(i.data.Flag));
			   String strDataTime = Math::Date::convertfmt(i.data.CPs.DataTime.c_str(), "%04d%02d%02d%02d%02d%02d", "%04d年%02d月%02d日 %02d时%02d分%02d秒");
               ui->lineEditDataTime->setText(QString::fromStdString(strDataTime));

			   
               // 遍历监测数据部分
               MonitorRow rw;
               for( auto& item : i.data.CPs.Value)
               {
                    if (item.first == "DataTime")
                    {
                        continue;
                    }
                    MonitorData itemData;
					itemData.mn = i.data.MN;
					itemData.qnTime = i.data.QN;
					itemData.datatime = i.data.CPs.DataTime;
					itemData.paramCode = item.first;
                    //String strParamCode = item.first;
                    //double val = 0.0f;
                    //String strMark = "N";
                    for (auto &kitem : item.second)
                    {
                        if (kitem.first == "Avg" || kitem.first == "Rtd")
                        {
                            Math::Tools::to_double(itemData.val, kitem.second);
                        } else if (kitem.first == "Flag")
                        {
                             itemData.mark = kitem.second;
                        }
                    }
                    rw.push_back(itemData);
                    // 此处可以根据需要对rw的监测数据进行入库处理（比如入库到MySQL、SqlServer、Sqlite、Qracle、Redis、MongoDB数据库等）
                    dbprocess_.insertMonitorData(itemData);
               }

			   // 往界面中的监测数据表格中填充数据
			   int totalRow = rw.size();
			   int currentRow = 0;
			   ui->tableWidget->clearContents();
			   ui->tableWidget->setRowCount(totalRow);
			   ui->tableWidget->setColumnCount(4);
			   for (auto dataItem : rw)
			   {
				   String strQNTime = Math::Date::convertfmt(dataItem.qnTime.substr(0, 14).c_str(), "%04d%02d%02d%02d%02d%02d", "%04d-%02d-%02d %02d:%02d:%02d");
				   String strDataTime = Math::Date::convertfmt(dataItem.datatime.c_str(), "%04d%02d%02d%02d%02d%02d", "%04d-%02d-%02d %02d:%02d:%02d");

				   QTableWidgetItem *newQNTimeItem = new QTableWidgetItem(QString::fromStdString(strQNTime));
				   ui->tableWidget->setItem(currentRow, 0, newQNTimeItem);

				   QTableWidgetItem *newDataTimeItem = new QTableWidgetItem(QString::fromStdString(strDataTime));
				   ui->tableWidget->setItem(currentRow, 1, newDataTimeItem);

				   QTableWidgetItem *newparamCodeItem = new QTableWidgetItem(QString::fromStdString(dataItem.paramCode));
				   ui->tableWidget->setItem(currentRow, 2, newparamCodeItem);

				   QTableWidgetItem *newValItem = new QTableWidgetItem(tr("%1").arg(dataItem.val));
				   ui->tableWidget->setItem(currentRow, 3, newValItem);

				   QTableWidgetItem *newMarkItem = new QTableWidgetItem(QString::fromStdString(dataItem.mark));
				   ui->tableWidget->setItem(currentRow, 4, newMarkItem);

				   currentRow++;
			   }
            }
        }
    }
}
