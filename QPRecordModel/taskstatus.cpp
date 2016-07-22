#include "taskstatus.h"

TaskStatus::TaskStatus():
    _statusID(0), _taskApplyID(0), _curState(0), _execUserID(2)
{
}

QDateTime TaskStatus::recvTime() const
{
    return _recvTime;
}

void TaskStatus::setRecvTime(const QDateTime &recvTime)
{
    _recvTime = recvTime;
}
QDateTime TaskStatus::readTime() const
{
    return _readTime;
}

void TaskStatus::setReadTime(const QDateTime &readTime)
{
    _readTime = readTime;
}
QDateTime TaskStatus::execTime() const
{
    return _execTime;
}

void TaskStatus::setExecTime(const QDateTime &execTime)
{
    _execTime = execTime;
}
QDateTime TaskStatus::finishTime() const
{
    return _finishTime;
}

void TaskStatus::setFinishTime(const QDateTime &finishTime)
{
    _finishTime = finishTime;
}


int TaskStatus::statusID() const
{
    return _statusID;
}

void TaskStatus::setStatusID(int statusID)
{
    _statusID = statusID;
}
int TaskStatus::taskApplyID() const
{
    return _taskApplyID;
}

void TaskStatus::setTaskApplyID(int taskApplyID)
{
    _taskApplyID = taskApplyID;
}
QDateTime TaskStatus::reportTime() const
{
    return _reportTime;
}

void TaskStatus::setReportTime(const QDateTime &reportTime)
{
    _reportTime = reportTime;
}
int TaskStatus::curState() const
{
    return _curState;
}

void TaskStatus::setCurState(int curState)
{
    _curState = curState;
}
int TaskStatus::execUserID() const
{
    return _execUserID;
}

void TaskStatus::setExecUserID(int execUserID)
{
    _execUserID = execUserID;
}












