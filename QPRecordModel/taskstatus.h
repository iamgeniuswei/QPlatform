#ifndef TASKSTATUS_H
#define TASKSTATUS_H
#include "dbmodel.h"
#include "dbmodel_global.h"
#include <QDateTime>
class DBMODELSHARED_EXPORT TaskStatus : public DBModel
{
public:
    TaskStatus();

    QDateTime recvTime() const;
    void setRecvTime(const QDateTime &recvTime);

    QDateTime readTime() const;
    void setReadTime(const QDateTime &readTime);

    QDateTime execTime() const;
    void setExecTime(const QDateTime &execTime);

    QDateTime finishTime() const;
    void setFinishTime(const QDateTime &finishTime);

    int statusID() const;
    void setStatusID(int statusID);

    int taskApplyID() const;
    void setTaskApplyID(int taskApplyID);

    QDateTime reportTime() const;
    void setReportTime(const QDateTime &reportTime);

    int curState() const;
    void setCurState(int curState);

    int execUserID() const;
    void setExecUserID(int execUserID);

private:
    int _statusID;
    int _taskApplyID;
    int _curState;
    int _execUserID;
    QDateTime _recvTime;
    QDateTime _readTime;
    QDateTime _execTime;
    QDateTime _finishTime;
    QDateTime _reportTime;
};

#endif // TASKSTATUS_H
