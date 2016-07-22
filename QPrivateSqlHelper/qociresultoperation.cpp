#include "qociresultoperation.h"
#include "sysresult.h"
#include "sqlerror.h"
#include <QSqlQuery>
#include <QDebug>
#include "qpsqlconnection.h"
QOCIResultOperation::QOCIResultOperation(QObject *parent)
    :QPOCIDataOperation(parent)
{
    setTableName("VIEW_RESULT_XYFX");
}

int QOCIResultOperation::InsertRecord(DBModel *dataModel, const QString &connName)
{
    SysResult *resultInfo = dynamic_cast<SysResult *>(dataModel);
    if(resultInfo)
    {
        QSqlDatabase db = QPSqlConnection::getDBbyName("TaskDB");
        QSqlQuery query(db);
        query.prepare("INSERT INTO T_RESULT(RESULT_APPLYID,RESULT_CONTENT,RESULT_DESCRIPTION,RESULT_STATUS,RESULT_SEAT,RESULT_SCHEDULE, RESULT_UPLOADTIME) "
                      "VALUES (:RESULT_APPLYID, :RESULT_CONTENT, :RESULT_DESCRIPTION, :RESULT_STATUS, :RESULT_SEAT, :RESULT_SCHEDULE, :RESULT_UPLOADTIME)");
        query.bindValue(":RESULT_APPLYID",resultInfo->getResultApplyId());
        query.bindValue(":RESULT_CONTENT",resultInfo->getResultContent());
        query.bindValue(":RESULT_DESCRIPTION",resultInfo->getResultDescription());
        query.bindValue(":RESULT_STATUS",resultInfo->getResultStatus());
        query.bindValue(":RESULT_SEAT",resultInfo->getResultSeat());
        query.bindValue(":RESULT_SCHEDULE",resultInfo->getResultSchedule());
        query.bindValue(":RESULT_UPLOADTIME",resultInfo->getResultReportTime());
        return ExecuteQSqlQuery(query);
    }
    else
    {
        QPErrorInfoQueue *queue = QPErrorInfoQueue::getInstance();
        queue->addErrorInfo(SqlError::errNo_PointIsNULL, SqlError::errStr_PointIsNull);
        return SqlError::retInsertRecordError;
    }
}

int QOCIResultOperation::DeleteRecord(DBModel *dataModel, const QString &connName)
{
    SysResult *resultInfo = dynamic_cast<SysResult *>(dataModel);
    if(resultInfo)
    {
        QString sql = "DELETE FROM T_RESULT where RESULT_ID =" + QString::number(resultInfo->getResultId(),10)/* + "'"*/;
        return ExecuteSql(sql, "TaskDB");
    }
    else
    {
        QPErrorInfoQueue *queue = QPErrorInfoQueue::getInstance();
        queue->addErrorInfo(SqlError::errNo_PointIsNULL, SqlError::errStr_PointIsNull);
        return SqlError::retInsertRecordError;
    }
}

int QOCIResultOperation::UpdateRecord(DBModel *dataModel, const QString &connName)
{
    SysResult *resultInfo = dynamic_cast<SysResult *>(dataModel);
    if(resultInfo)
    {
        QSqlQuery query;
        query.prepare("UPDATE T_RESULT SET RESULT_APPLYID=:RESULT_APPLYID,RESULT_CONTENT=:RESULT_CONTENT,RESULT_DESCRIPTION=:RESULT_DESCRIPTION,RESULT_STATUS=:RESULT_STATUS,RESULT_SEAT=:RESULT_SEAT,RESULT_SCHEDULE=:RESULT_SCHEDULE,RESULT_UPLOADTIME=:RESULT_UPLOADTIME where RESULT_ID=:RESULT_ID");
        query.bindValue(":RESULT_ID",resultInfo->getResultId());
        query.bindValue(":RESULT_APPLYID",resultInfo->getResultApplyId());
        query.bindValue(":RESULT_CONTENT",resultInfo->getResultContent());
        query.bindValue(":RESULT_DESCRIPTION",resultInfo->getResultDescription());
        query.bindValue(":RESULT_STATUS",resultInfo->getResultStatus());
        query.bindValue(":RESULT_SEAT",resultInfo->getResultSeat());
        query.bindValue(":RESULT_SCHEDULE",resultInfo->getResultSchedule());
        query.bindValue(":RESULT_UPLOADTIME",resultInfo->getResultReportTime());
        return ExecuteQSqlQuery(query);
    }
    else
    {
        QPErrorInfoQueue *queue = QPErrorInfoQueue::getInstance();
        queue->addErrorInfo(SqlError::errNo_PointIsNULL, SqlError::errStr_PointIsNull);
        return SqlError::retInsertRecordError;
    }
}

DBModel *QOCIResultOperation::QueryRecord(int _id)
{
    SysResult *resultInfo = new SysResult;
    QString sql = "SELECT * FROM T_RESULT where RESULT_ID =" + QString::number(_id,10);
    QSqlQuery query(sql);
    //if query success, only one row
    if(!(query.lastError().isValid()) && query.next())
    {
        resultInfo->setResultId(query.value("RESULT_ID").toInt());
        resultInfo->setResultApplyId(query.value("RESULT_APPLYID").toInt());
        resultInfo->setResultContent(query.value("RESULT_CONTENT").toString());
        resultInfo->setResultDescription(query.value("RESULT_DESCRIPTION").toString());
        resultInfo->setResultStatus(query.value("RESULT_STATUS").toInt());
        resultInfo->setResultSeat(query.value("RESULT_SEAT").toInt());
        resultInfo->setResultSchedule(query.value("RESULT_SCHEDULE").toInt());
        resultInfo->setResultReportTime(query.value("RESULT_UPLOADTIME").toDateTime());

    }
    else
    {
        QPErrorInfoQueue *queue = QPErrorInfoQueue::getInstance();
        queue->addErrorInfo(SqlError::errNo_NoRecord, query.lastError().text());
        return NULL;
    }
    return resultInfo;
}

DBModel *QOCIResultOperation::QueryRecord(const int _id, const QString &connName)
{
    SysResult *resultInfo = new SysResult;
    QString sql = "SELECT * FROM T_RESULT where RESULT_ID =" + QString::number(_id,10);
    if(!connName.isEmpty())
    {
        QSqlDatabase db = QPSqlConnection::getDBbyName("TaskDB");
        QSqlQuery query(sql, db);
        //if query success, only one row
        if(!(query.lastError().isValid()) && query.next())
        {
            resultInfo->setResultId(query.value("RESULT_ID").toInt());
            resultInfo->setResultApplyId(query.value("RESULT_APPLYID").toInt());
            resultInfo->setResultContent(query.value("RESULT_CONTENT").toString());
            resultInfo->setResultDescription(query.value("RESULT_DESCRIPTION").toString());
            resultInfo->setResultStatus(query.value("RESULT_STATUS").toInt());
            resultInfo->setResultSeat(query.value("RESULT_SEAT").toInt());
            resultInfo->setResultSchedule(query.value("RESULT_SCHEDULE").toInt());
            resultInfo->setResultReportTime(query.value("RESULT_UPLOADTIME").toDateTime());
        }
        else
        {
            QPErrorInfoQueue *queue = QPErrorInfoQueue::getInstance();
            queue->addErrorInfo(SqlError::errNo_NoRecord, query.lastError().text());
            return NULL;
        }
        return resultInfo;
    }
    else
    {
        return QueryRecord(_id);
    }
}
