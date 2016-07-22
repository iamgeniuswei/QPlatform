#include "qocitaskstatusoperation.h"
#include "taskstatus.h"
#include <QSqlDatabase>
#include "qpsqlconnection.h"
#include <QSqlQuery>
#include <QVariant>
#include "qperrorinfoqueue.h"
#include "sqlerror.h"

QOCITaskStatusOperation::QOCITaskStatusOperation(QObject *parent) :
    QPOCIDataOperation(parent)
{
}

int QOCITaskStatusOperation::InsertRecord(DBModel *dataModel, const QString &connName)
{
    TaskStatus *taskStatus = dynamic_cast<TaskStatus *>(dataModel);
    if(taskStatus)
    {
        QSqlDatabase db = QPSqlConnection::getDBbyName(connName);
        QSqlQuery query(db);
        query.prepare("INSERT INTO T_TASKSTATUS(TASK_EXECUSERID,TASK_RECV_TIME,TASK_CURRENT,TASK_APPLYID) "
                      "VALUES (:TASK_EXECUSERID,:TASK_RECV_TIME, :TASK_CURRENT, :TASK_APPLYID)");
        query.bindValue(":TASK_EXECUSERID", taskStatus->execUserID());
        query.bindValue(":TASK_RECV_TIME",taskStatus->recvTime());
        query.bindValue(":TASK_CURRENT", taskStatus->curState());
        query.bindValue(":TASK_APPLYID",taskStatus->taskApplyID());
        return ExecuteQSqlQuery(query);
    }
    else
    {
        QPErrorInfoQueue *queue = QPErrorInfoQueue::getInstance();
        queue->addErrorInfo(SqlError::errNo_PointIsNULL, SqlError::errStr_PointIsNull);
        return SqlError::retInsertRecordError;
    }
}

int QOCITaskStatusOperation::UpdateRecord(DBModel *dataModel, const QString &connName)
{
    TaskStatus *taskStatus = dynamic_cast<TaskStatus *>(dataModel);
    if(taskStatus)
    {
        QSqlDatabase db = QPSqlConnection::getDBbyName(connName);
        QSqlQuery query(db);
        if(!taskStatus->execTime().isNull())
        {
            query.prepare("UPDATE T_TASKSTATUS SET TASK_CURRENT=:TASK_CURRENT,TASK_READ_TIME=:TASK_READ_TIME,TASK_EXEC_TIME=:TASK_EXEC_TIME where TASK_APPLYID=:TASK_APPLYID");
            query.bindValue(":TASK_CURRENT",taskStatus->curState());
            query.bindValue(":TASK_READ_TIME",taskStatus->readTime());
            query.bindValue(":TASK_EXEC_TIME",taskStatus->execTime());
            query.bindValue(":TASK_APPLYID", taskStatus->taskApplyID());
        }
        else if(!taskStatus->reportTime().isNull())
        {
            query.prepare("UPDATE T_TASKSTATUS SET TASK_CURRENT=:TASK_CURRENT,TASK_FINISH_TIME=:TASK_FINISH_TIME,TASK_REPORT_TIME=:TASK_REPORT_TIME where TASK_APPLYID=:TASK_APPLYID");
            query.bindValue(":TASK_CURRENT",taskStatus->curState());
            query.bindValue(":TASK_FINISH_TIME",taskStatus->finishTime());
            query.bindValue(":TASK_REPORT_TIME",taskStatus->reportTime());
            query.bindValue(":TASK_APPLYID", taskStatus->taskApplyID());
        }
        return ExecuteQSqlQuery(query);
    }
    else
    {
        QPErrorInfoQueue *queue = QPErrorInfoQueue::getInstance();
        queue->addErrorInfo(SqlError::errNo_PointIsNULL, SqlError::errStr_PointIsNull);
        return SqlError::retInsertRecordError;
    }
}
