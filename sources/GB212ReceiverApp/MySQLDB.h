#pragma once
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include "pub.h"
#include <QStringList>


class MySQLDB
{
public:
	MySQLDB();

    // 获取可用数据库列表
    QStringList getDBList();

	// 设置数据库连接信息
	void setDBInfo(const QString &host, const quint16 port, const QString &username, const QString &pwd, const QString &dbname);

	// 连接MySQL数据库
	bool connectDB();

	// 查询数据库中监测数据表 monitordata
	bool queryMonitorData();

	// 插入数据记录到监测数据表 monitordata
	bool insertMonitorData(const MonitorData &record);

	~MySQLDB();

private:
	QString host_;
	quint16 port_;
	QString username_;
	QString password_;
	QString dbname_;

    QSqlDatabase db_;
};

