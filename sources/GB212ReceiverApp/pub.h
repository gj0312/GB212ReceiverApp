#ifndef PUB_H
#define PUB_H
#include "type.h"

// 监测数据结构
typedef struct t_MonitorData
{
	// 站点编码
	String mn;
	// 数据时间
	String datatime;
	// 监测因子编码（HJ212-2017编码）
    String paramCode;
	// 监测值
    double val;
	// 数据标记位
    String mark;
	// QN 请求时间
	String qnTime;
}MonitorData;
typedef std::vector<MonitorData> MonitorRow;
typedef std::map<String, MonitorData> MonitorMap;

#endif // PUB_H
