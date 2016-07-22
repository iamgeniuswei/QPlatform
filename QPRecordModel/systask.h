#ifndef SYSTASK_H
#define SYSTASK_H

#include "dbmodel_global.h"
#include "dbmodel.h"
#include <QString>
#include <QDateTime>

class DBMODELSHARED_EXPORT SysTask : public DBModel
{
public:
    SysTask(){}    
    int getTaskId() const;
    void setTaskId(int value);

    int getTaskApplyID() const;
    void setTaskApplyID(int value);

    int getTaskSeat() const;
    void setTaskSeat(int value);

    QString getTaskAddress() const;
    void setTaskAddress(const QString &value);

    int getTaskType() const;
    void setTaskType(int value);

    QString getTaskTarget() const;
    void setTaskTarget(const QString &value);

    QString getTaskDescription() const;
    void setTaskDescription(const QString &value);

    QDateTime getTaskArriveTime() const;
    void setTaskArriveTime(const QDateTime &value);

    int getTaskIsRead() const;
    void setTaskIsRead(int value);

    int getTaskIsUpload() const;
    void setTaskIsUpload(int value);

    QString getTaskContent() const;
    void setTaskContent(const QString &value);

    QString getTaskAttachNote() const;
    void setTaskAttachNote(const QString &value);

private:
    int taskId;
    int taskApplyID;
    int taskSeat;
    QString taskAddress;
    int taskType;
    QString taskTarget;
    QString taskDescription;
    QDateTime taskArriveTime;
    int taskIsRead;
    int taskIsUpload;
    QString taskContent;
    QString taskAttachNote;
};

#endif // SYSTASK_H
