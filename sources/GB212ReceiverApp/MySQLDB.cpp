#include "MySQLDB.h"
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QDebug>
#include "func.h"

#pragma execution_character_set("utf-8")

MySQLDB::MySQLDB()
{
}

// 获取可用数据库列表
QStringList MySQLDB::getDBList()
{
    qDebug() << "avaliable db drivers:";
    QStringList drivers = QSqlDatabase::drivers();
    foreach(QString driver, drivers)
    {
        qDebug() << drivers;
    }

    return drivers;
}

// 设置数据库连接信息
void MySQLDB::setDBInfo(const QString & host, const quint16 port, const QString & username, const QString & pwd, const QString & dbname)
{
	host_ = host;
	port_ = port;
	username_ = username;
	password_ = pwd;
	dbname_ = dbname;
}

MySQLDB::~MySQLDB()
{
}

// 连接MySQL数据库(通过ODBC方式连接)
// https://blog.csdn.net/joey_ro/article/details/105411135
bool MySQLDB::connectDB()
{
    //QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db_ = QSqlDatabase::addDatabase("QODBC3");
    db_.setHostName(host_);
    db_.setPort(port_);
    db_.setDatabaseName(dbname_);
    db_.setUserName(username_);
    db_.setPassword(password_);
    bool bConnected = db_.open();
	if (bConnected)
	{
        qDebug() << "connect to mysql db successful!";
		return true;
	}
	else {
        qDebug() << "connect to mysql db falied!" << db_.lastError().text();
		return false;
	}
}

// 查询数据库中监测数据表 monitordata
bool MySQLDB::queryMonitorData()
{
    //查询数据库中所有表的名称
    QStringList tables = db_.tables();
    foreach(QString table, tables)
        qDebug()<<table;

    //ODBC查询数据
    QSqlQuery result = db_.exec("select * from monitordata");
    while(result.next()){
        qDebug()<<"mn:"<<result.value("mn").toString();
        qDebug()<<"datatime:"<<result.value("datatime").toString();
        qDebug()<<"paramCode:"<<result.value("paramCode").toString();
        qDebug()<<"val:"<<result.value("val").toDouble()<<endl;
        qDebug()<<"mark:"<<result.value("mark").toString()<<endl;
    }

	return true;
}

// 插入数据记录到监测数据表 monitordata
bool MySQLDB::insertMonitorData(const MonitorData &record)
{
    // ODBC插入数据
	String strQNTime = Math::Date::convertfmt(record.qnTime.substr(0, 14).c_str(), "%04d%02d%02d%02d%02d%02d", "%04d-%02d-%02d %02d:%02d:%02d");
	String strDataTime = Math::Date::convertfmt(record.datatime.c_str(), "%04d%02d%02d%02d%02d%02d", "%04d-%02d-%02d %02d:%02d:%02d");
    QString strSql = QString("insert into monitordata(mn,qntime,datatime,paramCode,val,mark) values('%1','%2','%3', '%4', %5,'%6')")
            .arg(QString::fromStdString(record.mn))
			.arg(QString::fromStdString(strQNTime))
            .arg(QString::fromStdString(strDataTime))
            .arg(QString::fromStdString(record.paramCode))
            .arg(record.val)
            .arg(QString::fromStdString(record.mark));   
	QSqlQuery query(db_);
	if (query.exec(strSql))
	{
		qDebug() << "插入数据成功！";
		return true;
	}
	else
	{
		qDebug() << "插入数据失败！";
		return false;
	}
}
