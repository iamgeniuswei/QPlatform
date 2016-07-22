#include "qocitaskoperation.h"
#include "sqlerror.h"
#include "qpocisqlcommand.h"
#include "systask.h"
#include "qpsqlconnection.h"
#include <QSqlQuery>
#include <QDebug>

QOCITaskOperation::QOCITaskOperation(QObject *parent):
    QPOCIDataOperation(parent)
{
    setTableName("VIEW_TASK_XYFX");
}

//int QOCITaskOperation::InsertRecord(DBModel *dataModel)
//{
//    SysTask *taskInfo = dynamic_cast<SysTask *>(dataModel);
//    if(taskInfo)
//    {
//        QSqlQuery query;
//        query.prepare("INSERT INTO T_TASK(TASK_ID,TASK_NAME,TASK_TYPE,TASK_APPLICANT,TASK_APPLICANT_TIME,TASK_APPROVER,TASK_APPORVE_TIME,TASK_ARRIVE_TIME,TASK_OBJECT_CODE,TASK_DESCRIPTION,DISTRIBUTE_OPERATOR,DISTRIBUTE_TIME,DISTRIBUTE_DESCRIPTION,TASK_ISREAD,TASK_ISUPLOAD,TASK_ORIGIN_ID,TASK_SEAT) "
//                      "VALUES (:TASK_ID,:TASK_NAME,:TASK_TYPE,:TASK_APPLICANT,:TASK_APPLICANT_TIME,:TASK_APPROVER,:TASK_APPORVE_TIME,:TASK_ARRIVE_TIME,:TASK_OBJECT_CODE,:TASK_DESCRIPTION,:DISTRIBUTE_OPERATOR,:DISTRIBUTE_TIME,:DISTRIBUTE_DESCRIPTION,:TASK_ISREAD,:TASK_ISUPLOAD,:TASK_ORIGIN_ID,:TASK_SEAT)");
//        query.bindValue(":TASK_ID",taskInfo->getTaskId());
//        query.bindValue(":TASK_NAME",taskInfo->getTaskName());
//        query.bindValue(":TASK_TYPE",taskInfo->getTaskType());
//        query.bindValue(":TASK_APPLICANT",taskInfo->getTaskApplicant());
//        query.bindValue(":TASK_APPLICANT_TIME",taskInfo->getTaskApplicantTime());
//        query.bindValue(":TASK_APPROVER",taskInfo->getTaskApprover());
//        query.bindValue(":TASK_APPORVE_TIME",taskInfo->getTaskApporveTime());
//        query.bindValue(":TASK_ARRIVE_TIME",taskInfo->getTaskArriveTime());
//        query.bindValue(":TASK_OBJECT_CODE",taskInfo->getTaskObjectCode());
//        query.bindValue(":TASK_DESCRIPTION",taskInfo->getTaskDescription());
//        query.bindValue(":DISTRIBUTE_OPERATOR",taskInfo->getDistributeOperator());
//        query.bindValue(":DISTRIBUTE_TIME",taskInfo->getDistributeTime());
//        query.bindValue(":DISTRIBUTE_DESCRIPTION",taskInfo->getDistributeDescription());
//        query.bindValue(":TASK_ISREAD",taskInfo->getTaskIsRead());
//        query.bindValue(":TASK_ISUPLOAD",taskInfo->getTaskIsUpload());
//        query.bindValue(":TASK_ORIGIN_ID",taskInfo->getTaskOriginId());
//        query.bindValue(":TASK_SEAT",taskInfo->getTaskSeat());
//        return ExecuteQSqlQuery(query);
//    }
//    else
//    {
//        ErrorInfo info;
//        info.setErrorNo(SqlError::errNo_PointIsNULL);
//        info.setErrorMsg(SqlError::errStr_PointIsNull);
//        ErrorInfoQueue queue;
//        queue.addErrorInfo(info);
//        return SqlError::retInsertRecordError;
//    }
//}

int QOCITaskOperation::InsertRecord(DBModel *dataModel, const QString &connName)
{
    SysTask *taskInfo = dynamic_cast<SysTask *>(dataModel);
    if(taskInfo)
    {
        QSqlDatabase db = QPSqlConnection::getDBbyName(connName);
        QSqlQuery query(db);
        query.prepare("INSERT INTO T_TASK(TASK_APPLYID,TASK_SEAT,TASK_ADDRESS,TASK_TYPE,TASK_TARGET,TASK_DESCRIPTION,TASK_ARRIVE_TIME,TASK_ISREAD,TASK_ISUPLOAD,TASK_CONTENT,TASK_ATTACHNOTE) "
                      "VALUES (:TASK_APPLYID,:TASK_SEAT,:TASK_ADDRESS,:TASK_TYPE,:TASK_TARGET,:TASK_DESCRIPTION,:TASK_ARRIVE_TIME,:TASK_ISREAD,:TASK_ISUPLOAD,:TASK_CONTENT,:TASK_ATTACHNOTE)");
        query.bindValue(":TASK_APPLYID",taskInfo->getTaskApplyID());
        query.bindValue(":TASK_SEAT",taskInfo->getTaskSeat());
        query.bindValue(":TASK_ADDRESS", taskInfo->getTaskAddress());
        query.bindValue(":TASK_TYPE",taskInfo->getTaskType());
        query.bindValue(":TASK_TARGET",taskInfo->getTaskTarget());
        query.bindValue(":TASK_DESCRIPTION",taskInfo->getTaskDescription());
        query.bindValue(":TASK_ARRIVE_TIME",taskInfo->getTaskArriveTime());
        query.bindValue(":TASK_ISREAD",taskInfo->getTaskIsRead());
        query.bindValue(":TASK_ISUPLOAD",taskInfo->getTaskIsUpload());
        query.bindValue(":TASK_CONTENT",taskInfo->getTaskContent());
        query.bindValue(":TASK_ATTACHNOTE",taskInfo->getTaskAttachNote());
        return ExecuteQSqlQuery(query);
    }
    else
    {
        QPErrorInfoQueue *queue = QPErrorInfoQueue::getInstance();
        queue->addErrorInfo(SqlError::errNo_PointIsNULL, SqlError::errStr_PointIsNull);
        return SqlError::retInsertRecordError;
    }
}

int QOCITaskOperation::DeleteRecord(DBModel *dataModel)
{
    SysTask *taskInfo = dynamic_cast<SysTask *>(dataModel);
    if(taskInfo)
    {
        QString sql = "DELETE FROM T_TASK where TASK_ID =" + QString::number(taskInfo->getTaskId(),10);
        return ExecuteSql(sql, "TaskDB");
    }
    else
    {
        QPErrorInfoQueue *queue = QPErrorInfoQueue::getInstance();
        queue->addErrorInfo(SqlError::errNo_PointIsNULL, SqlError::errStr_PointIsNull);
        return SqlError::retInsertRecordError;
    }
}

int QOCITaskOperation::UpdateRecord(DBModel *dataModel, const QString &connName)
{
    SysTask *taskInfo = dynamic_cast<SysTask *>(dataModel);
    if(taskInfo)
    {
        QSqlDatabase db = QPSqlConnection::getDBbyName("TaskDB");
        QSqlQuery query(db);
        query.prepare("UPDATE T_TASK SET TASK_APPLYID=:TASK_APPLYID,TASK_SEAT=:TASK_SEAT,TASK_ADDRESS=:TASK_ADDRESS,TASK_TYPE=:TASK_TYPE,TASK_TARGET=:TASK_TARGET,TASK_DESCRIPTION=:TASK_DESCRIPTION,TASK_ARRIVE_TIME=:TASK_ARRIVE_TIME,TASK_ISREAD=:TASK_ISREAD,TASK_ISUPLOAD=:TASK_ISUPLOAD,TASK_CONTENT=:TASK_CONTENT,TASK_ATTACHNOTE=:TASK_ATTACHNOTE where TASK_ID=:TASK_ID");
        query.bindValue(":TASK_ID",taskInfo->getTaskId());
        query.bindValue(":TASK_APPLYID",taskInfo->getTaskApplyID());
        query.bindValue(":TASK_SEAT",taskInfo->getTaskSeat());
        query.bindValue(":TASK_ADDRESS", taskInfo->getTaskAddress());
        query.bindValue(":TASK_TYPE",taskInfo->getTaskType());
        query.bindValue(":TASK_TARGET",taskInfo->getTaskTarget());
        query.bindValue(":TASK_DESCRIPTION",taskInfo->getTaskDescription());
        query.bindValue(":TASK_ARRIVE_TIME",taskInfo->getTaskArriveTime());
        query.bindValue(":TASK_ISREAD",taskInfo->getTaskIsRead());
        query.bindValue(":TASK_ISUPLOAD",taskInfo->getTaskIsUpload());
        query.bindValue(":TASK_CONTENT",taskInfo->getTaskContent());
        query.bindValue(":TASK_ATTACHNOTE",taskInfo->getTaskAttachNote());
        return ExecuteQSqlQuery(query);
    }
    else
    {
        QPErrorInfoQueue *queue = QPErrorInfoQueue::getInstance();
        queue->addErrorInfo(SqlError::errNo_PointIsNULL, SqlError::errStr_PointIsNull);
        return SqlError::retInsertRecordError;
    }
}

DBModel *QOCITaskOperation::QueryRecord(int _id)
{
    SysTask *taskInfo = new SysTask;
    QString sql = "SELECT * FROM T_TASK where TASK_ID =" + QString::number(_id,10);    
    QSqlQuery query(sql);
    //if query success, only one row
    if(!(query.lastError().isValid()) && query.next())
    {
        qDebug() << query.isValid();
        taskInfo->setTaskId(query.value("TASK_ID").toInt());
        taskInfo->setTaskApplyID(query.value("TASK_APPLYID").toInt());
        taskInfo->setTaskSeat(query.value("TASK_SEAT").toInt());
        taskInfo->setTaskAddress(query.value("TASK_ADDRESS").toString());
        taskInfo->setTaskType(query.value("TASK_TYPE").toInt());
        taskInfo->setTaskTarget(query.value("TASK_TARGET").toString());
        taskInfo->setTaskDescription(query.value("TASK_DESCRIPTION").toString());
        taskInfo->setTaskArriveTime(query.value("TASK_ARRIVE_TIME").toDateTime());
        taskInfo->setTaskIsRead(query.value("TASK_ISREAD").toInt());
        taskInfo->setTaskIsUpload(query.value("TASK_ISUPLOAD").toInt());
        taskInfo->setTaskContent(query.value("TASK_CONTENT").toString());
        taskInfo->setTaskAttachNote(query.value("TASK_ATTACHNOTE").toString());
    }
    else
    {
        QPErrorInfoQueue *queue = QPErrorInfoQueue::getInstance();
        queue->addErrorInfo(SqlError::errNo_NoRecord, query.lastError().text());
        return NULL;
    }

    return taskInfo;
}

DBModel *QOCITaskOperation::QueryRecord(const int _id, const QString &connName)
{
    SysTask *taskInfo = new SysTask;
    QString sql = "SELECT * FROM T_TASK where TASK_ID =" + QString::number(_id,10);
    if(!connName.isEmpty())
    {
        QSqlDatabase db = QPSqlConnection::getDBbyName("TaskDB");
        QSqlQuery query(sql, db);
        //if query success, only one row
        if(!(query.lastError().isValid()) && query.next())
        {
            qDebug() << query.isValid();
            taskInfo->setTaskId(query.value("TASK_ID").toInt());
            taskInfo->setTaskApplyID(query.value("TASK_APPLYID").toInt());
            taskInfo->setTaskSeat(query.value("TASK_SEAT").toInt());
            taskInfo->setTaskAddress(query.value("TASK_ADDRESS").toString());
            taskInfo->setTaskType(query.value("TASK_TYPE").toInt());
            taskInfo->setTaskTarget(query.value("TASK_TARGET").toString());
            taskInfo->setTaskDescription(query.value("TASK_DESCRIPTION").toString());
            taskInfo->setTaskArriveTime(query.value("TASK_ARRIVE_TIME").toDateTime());
            taskInfo->setTaskIsRead(query.value("TASK_ISREAD").toInt());
            taskInfo->setTaskIsUpload(query.value("TASK_ISUPLOAD").toInt());
            taskInfo->setTaskContent(query.value("TASK_CONTENT").toString());
            taskInfo->setTaskAttachNote(query.value("TASK_ATTACHNOTE").toString());
        }
        else
        {
            QPErrorInfoQueue *queue = QPErrorInfoQueue::getInstance();
            queue->addErrorInfo(SqlError::errNo_NoRecord, query.lastError().text());
            return NULL;
        }
        return taskInfo;
    }
    else
    {
        return QueryRecord(_id);
    }

}

DBModel *QOCITaskOperation::QueryRecord(const QString &condition, const QString &connName)
{
    QString sql;
    if(!condition.isEmpty())
    {
        sql = "SELECT * FROM T_TASK WHERE " + condition;
    }
    else
        sql = "SELECT * FROM T_TASK";

    if(!connName.isEmpty())
    {
        SysTask *taskInfo = new SysTask;
        QSqlDatabase db = QPSqlConnection::getDBbyName("TaskDB");
        QSqlQuery query(sql, db);
        //if query success, only one row
        if(!(query.lastError().isValid()) && query.next())
        {
            taskInfo->setTaskId(query.value("TASK_ID").toInt());
            taskInfo->setTaskApplyID(query.value("TASK_APPLYID").toInt());
            taskInfo->setTaskSeat(query.value("TASK_SEAT").toInt());
            taskInfo->setTaskAddress(query.value("TASK_ADDRESS").toString());
            taskInfo->setTaskType(query.value("TASK_TYPE").toInt());
            taskInfo->setTaskTarget(query.value("TASK_TARGET").toString());
            taskInfo->setTaskDescription(query.value("TASK_DESCRIPTION").toString());
            taskInfo->setTaskArriveTime(query.value("TASK_ARRIVE_TIME").toDateTime());
            taskInfo->setTaskIsRead(query.value("TASK_ISREAD").toInt());
            taskInfo->setTaskIsUpload(query.value("TASK_ISUPLOAD").toInt());
            taskInfo->setTaskContent(query.value("TASK_CONTENT").toString());
            taskInfo->setTaskAttachNote(query.value("TASK_ATTACHNOTE").toString());
        }
        else
        {
            QPErrorInfo info;
            info.setErrorNo(SqlError::errNo_NoRecord);
            info.setErrorMsg(query.lastError().text());
            QPErrorInfoQueue *queue = QPErrorInfoQueue::getInstance();
            queue->addErrorInfo(info);
            delete taskInfo;
            return NULL;
        }
        return taskInfo;
    }
    else
    {
//        return QueryRecord(condition);
        return nullptr;
    }
}

DBModel *QOCITaskOperation::QueryByOrigin(int _id)
{
    SysTask *taskInfo = new SysTask;
    QString sql = "SELECT * FROM T_TASK where TASK_ORIGIN_ID =" + QString::number(_id,10);
    QSqlDatabase db = QPSqlConnection::getDBbyName("TaskDB");
    QSqlQuery query(sql, db);
    //if query success, only one row
    if(!(query.lastError().isValid()) && query.next())
    {
        qDebug() << query.isValid();
        taskInfo->setTaskId(query.value("TASK_ID").toInt());
        taskInfo->setTaskApplyID(query.value("TASK_APPLYID").toInt());
        taskInfo->setTaskSeat(query.value("TASK_SEAT").toInt());
        taskInfo->setTaskAddress(query.value("TASK_ADDRESS").toString());
        taskInfo->setTaskType(query.value("TASK_TYPE").toInt());
        taskInfo->setTaskTarget(query.value("TASK_TARGET").toString());
        taskInfo->setTaskDescription(query.value("TASK_DESCRIPTION").toString());
        taskInfo->setTaskArriveTime(query.value("TASK_ARRIVE_TIME").toDateTime());
        taskInfo->setTaskIsRead(query.value("TASK_ISREAD").toInt());
        taskInfo->setTaskIsUpload(query.value("TASK_ISUPLOAD").toInt());
        taskInfo->setTaskContent(query.value("TASK_CONTENT").toString());
        taskInfo->setTaskAttachNote(query.value("TASK_ATTACHNOTE").toString());
    }
    else
    {
        QPErrorInfoQueue *queue = QPErrorInfoQueue::getInstance();
        queue->addErrorInfo(SqlError::errNo_NoRecord, query.lastError().text());
        return NULL;
    }
    return taskInfo;
}

//bool QOCITaskOperation::QueryPage(QSqlQueryModel *model, int index, int step, const QString &condition)
//{
//    SqlCommand *command = new QOCISqlCommand;
//    if(command->queryPage(model, _tableName, index, step, condition))
//    {
//        delete command;
//        command = NULL;
//        return true;
//    }
//    else
//    {
//        delete command;
//        command = NULL;
//        return false;
//    }
//}

//int QOCITaskOperation::QueryCount(const QString &condition)
//{
//    SqlCommand *command = new QOCISqlCommand;
//    int count = command->queryCount(_tableName, condition);
//    delete command;
//    command = NULL;
//    return count;
//}
