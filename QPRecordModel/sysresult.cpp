#include "sysresult.h"





int SysResult::getResultId() const
{
    return resultId;
}

void SysResult::setResultId(int value)
{
    resultId = value;
}
int SysResult::getResultApplyId() const
{
    return resultApplyId;
}

void SysResult::setResultApplyId(int value)
{
    resultApplyId = value;
}
QString SysResult::getResultContent() const
{
    return resultContent;
}

void SysResult::setResultContent(const QString &value)
{
    resultContent = value;
}
QString SysResult::getResultDescription() const
{
    return resultDescription;
}

void SysResult::setResultDescription(const QString &value)
{
    resultDescription = value;
}
int SysResult::getResultStatus() const
{
    return resultStatus;
}

void SysResult::setResultStatus(int value)
{
    resultStatus = value;
}
int SysResult::getResultSeat() const
{
    return resultSeat;
}

void SysResult::setResultSeat(int value)
{
    resultSeat = value;
}
int SysResult::getResultSchedule() const
{
    return resultSchedule;
}

void SysResult::setResultSchedule(int value)
{
    resultSchedule = value;
}
QDateTime SysResult::getResultReportTime() const
{
    return resultReportTime;
}

void SysResult::setResultReportTime(const QDateTime &value)
{
    resultReportTime = value;
}







