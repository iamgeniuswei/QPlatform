#include "systask.h"





















int SysTask::getTaskId() const
{
    return taskId;
}

void SysTask::setTaskId(int value)
{
    taskId = value;
}
int SysTask::getTaskApplyID() const
{
    return taskApplyID;
}

void SysTask::setTaskApplyID(int value)
{
    taskApplyID = value;
}
int SysTask::getTaskSeat() const
{
    return taskSeat;
}

void SysTask::setTaskSeat(int value)
{
    taskSeat = value;
}
QString SysTask::getTaskAddress() const
{
    return taskAddress;
}

void SysTask::setTaskAddress(const QString &value)
{
    taskAddress = value;
}
int SysTask::getTaskType() const
{
    return taskType;
}

void SysTask::setTaskType(int value)
{
    taskType = value;
}
QString SysTask::getTaskTarget() const
{
    return taskTarget;
}

void SysTask::setTaskTarget(const QString &value)
{
    taskTarget = value;
}
QString SysTask::getTaskDescription() const
{
    return taskDescription;
}

void SysTask::setTaskDescription(const QString &value)
{
    taskDescription = value;
}
QDateTime SysTask::getTaskArriveTime() const
{
    return taskArriveTime;
}

void SysTask::setTaskArriveTime(const QDateTime &value)
{
    taskArriveTime = value;
}
int SysTask::getTaskIsRead() const
{
    return taskIsRead;
}

void SysTask::setTaskIsRead(int value)
{
    taskIsRead = value;
}
int SysTask::getTaskIsUpload() const
{
    return taskIsUpload;
}

void SysTask::setTaskIsUpload(int value)
{
    taskIsUpload = value;
}
QString SysTask::getTaskContent() const
{
    return taskContent;
}

void SysTask::setTaskContent(const QString &value)
{
    taskContent = value;
}
QString SysTask::getTaskAttachNote() const
{
    return taskAttachNote;
}

void SysTask::setTaskAttachNote(const QString &value)
{
    taskAttachNote = value;
}











