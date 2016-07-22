#include "syslog.h"


int SysLog::getLogId() const
{
    return logId;
}

void SysLog::setLogId(int value)
{
    logId = value;
}

int SysLog::getLogTypeId() const
{
    return logTypeId;
}

void SysLog::setLogTypeId(int value)
{
    logTypeId = value;
}
QString SysLog::getLogDetail() const
{
    return logDetail;
}

void SysLog::setLogDetail(const QString &value)
{
    logDetail = value;
}
QDateTime SysLog::getLogOperateTime() const
{
    return logOperateTime;
}

void SysLog::setLogOperateTime(const QDateTime &value)
{
    logOperateTime = value;
}


int SysLog::getLogUserID() const
{
    return logUserID;
}

void SysLog::setLogUserID(int value)
{
    logUserID = value;
}







