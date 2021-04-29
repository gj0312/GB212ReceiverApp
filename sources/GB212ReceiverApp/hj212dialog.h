#ifndef HJ212DIALOG_H
#define HJ212DIALOG_H

#include <QDialog>
#include <QTcpServer>      // 监听套接字
#include <QTcpSocket>      // 通信套接字

#include "MySQLDB.h"

namespace Ui {
class HJ212Dialog;
}

class HJ212Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit HJ212Dialog(QWidget *parent = nullptr);
    ~HJ212Dialog();

private slots:

    void on_btnStop_clicked();

    void on_btnListen_clicked();

    //  处理客户端的连接请求
    void handleAccept();
    // 解析客户端上传的报文
    void handleRecevice();

private:
    Ui::HJ212Dialog *ui;

    QTcpServer *tcpServer;      // 监听套接字
    QTcpSocket *tcpSocket;    // 通信套接字

	// MySQL数据库处理类对象
    MySQLDB dbprocess_;
};

#endif // HJ212DIALOG_H
