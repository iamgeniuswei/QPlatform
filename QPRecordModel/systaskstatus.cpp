#include "systaskstatus.h"

int SysTaskStatus::getStatusId() const
{
    return statusId;
}

void SysTaskStatus::setStatusId(int value)
{
    statusId = value;
}
int SysTaskStatus::getStatusOriginid() const
{
    return statusOriginid;
}

void SysTaskStatus::setStatusOriginid(int value)
{
    statusOriginid = value;
}
int SysTaskStatus::getStatusTypeid() const
{
    return statusTypeid;
}

void SysTaskStatus::setStatusTypeid(int value)
{
    statusTypeid = value;
}
QString SysTaskStatus::getStatusReporter() const
{
    return statusReporter;
}

void SysTaskStatus::setStatusReporter(const QString &value)
{
    statusReporter = value;
}
int SysTaskStatus::getStatusIsfinished() const
{
    return statusIsfinished;
}

void SysTaskStatus::setStatusIsfinished(int value)
{
    statusIsfinished = value;
}
QDateTime SysTaskStatus::getStatusFinishedtime() const
{
    return statusFinishedtime;
}

void SysTaskStatus::setStatusFinishedtime(const QDateTime &value)
{
    statusFinishedtime = value;
}
QString SysTaskStatus::getStatusDescription() const
{
    return statusDescription;
}

void SysTaskStatus::setStatusDescription(const QString &value)
{
    statusDescription = value;
}






