#include "qocilogoperation.h"
#include "qpsqlcommand.h"
#include "qpocisqlcommand.h"
#include "sqlerror.h"
#include "syslog.h"
#include <QSqlQuery>
#include <QVariant>
#include "qpsqlconnection.h"
QOCILogOperation::QOCILogOperation(QObject *parent)
    :QPOCIDataOperation(parent)
{
    setTableName("T_LOG");
}

int QOCILogOperation::InsertRecord(DBModel *dataModel, const QString &connName)
{
    Q_UNUSED(connName);
    SysLog *logInfo = dynamic_cast<SysLog *>(dataModel);
    if(logInfo)
    {
        QSqlDatabase db = QPSqlConnection::getDBbyName("TaskDB");
        QSqlQuery query(db);
        query.prepare("INSERT INTO T_LOG(LOG_TYPEID, LOG_USERID, LOG_DETAIL, LOG_OPERATETIME) "
                      "VALUES (:LOG_TYPEID, :LOG_USERID, :LOG_DETAIL, :LOG_OPERATETIME)");
        query.bindValue(":LOG_USERID", logInfo->getLogUserID());
        query.bindValue(":LOG_TYPEID", logInfo->getLogTypeId());
        query.bindValue(":LOG_DETAIL", logInfo->getLogDetail());
        query.bindValue(":LOG_OPERATETIME", logInfo->getLogOperateTime());
        return ExecuteQSqlQuery(query);
    }
    else
    {
        QPErrorInfoQueue *queue = QPErrorInfoQueue::getInstance();
        queue->addErrorInfo(SqlError::errNo_PointIsNULL, SqlError::errStr_PointIsNull);
        return SqlError::retInsertRecordError;
    }
}

//int QOCILogOperation::InsertRecord(DBModel *dataModel)
//{
//    SysLog *logInfo = dynamic_cast<SysLog *>(dataModel);
//    if(logInfo)
//    {
//        QSqlDatabase db = SqlConnection::getDBbyName("TaskDB");
//        QSqlQuery query(db);
//        query.prepare("INSERT INTO T_LOG(LOG_TYPEID, LOG_USERID, LOG_DETAIL, LOG_OPERATETIME) "
//                      "VALUES (:LOG_TYPEID, :LOG_USERID, :LOG_DETAIL, :LOG_OPERATETIME)");
//        query.bindValue(":LOG_USERID", logInfo->getLogUserID());
//        query.bindValue(":LOG_TYPEID", logInfo->getLogTypeId());
//        query.bindValue(":LOG_DETAIL", logInfo->getLogDetail());
//        query.bindValue(":LOG_OPERATETIME", logInfo->getLogOperateTime());
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

int QOCILogOperation::DeleteRecord(DBModel *dataModel)
{
    SysLog *logInfo = dynamic_cast<SysLog *>(dataModel);
    if(logInfo)
    {
        QString sql = "DELETE FROM T_LOG where LOG_ID =" + QString::number(logInfo->getLogId(),10);
        return ExecuteSql(sql, "TaskDB");
    }
    else
    {
        QPErrorInfoQueue *queue = QPErrorInfoQueue::getInstance();
        queue->addErrorInfo(SqlError::errNo_PointIsNULL, SqlError::errStr_PointIsNull);
        return SqlError::retInsertRecordError;
    }
}

int QOCILogOperation::UpdateRecord(DBModel *dataModel)
{
    SysLog *logInfo = dynamic_cast<SysLog *>(dataModel);
    if(logInfo)
    {
        QSqlQuery query;
        query.prepare("UPDATE T_LOG SET LOG_USERNAME =:LOG_USERNAME, LOG_TYPEID=:LOG_TYPEID, LOG_DETAIL=:LOG_DETAIL, LOG_OPERATETIME=:LOG_OPERATETIME where LOG_ID=:LOG_ID");
        query.bindValue(":LOG_USERNAME", logInfo->getLogUserID());
        query.bindValue(":LOG_TYPEID", logInfo->getLogTypeId());
        query.bindValue(":LOG_DETAIL", logInfo->getLogDetail());
        query.bindValue(":LOG_OPERATETIME", logInfo->getLogOperateTime());
        return ExecuteQSqlQuery(query);
    }
    else
    {
        QPErrorInfoQueue *queue = QPErrorInfoQueue::getInstance();
        queue->addErrorInfo(SqlError::errNo_PointIsNULL, SqlError::errStr_PointIsNull);
        return SqlError::retInsertRecordError;
    }
}

DBModel *QOCILogOperation::QueryRecord(int _id)
{
    SysLog *logInfo = new SysLog;
    QString sql = "SELECT * FROM T_LOG where LOG_ID =" + QString::number(_id,10);
    QSqlQuery query(sql);
    //if query success, only one row
    if(!(query.lastError().isValid()) && query.next())
    {
        logInfo->setLogId(query.value("LOG_ID").toInt());
        logInfo->setLogUserID(query.value("LOG_USERID").toInt());
        logInfo->setLogTypeId(query.value("LOG_TYPEID").toInt());
        logInfo->setLogDetail(query.value("LOG_DETAIL").toString());
        logInfo->setLogOperateTime(query.value("LOG_OPERATETIME").toDateTime());
    }
    else
    {
        QPErrorInfoQueue *queue = QPErrorInfoQueue::getInstance();
        queue->addErrorInfo(SqlError::errNo_NoRecord, query.lastError().text());
        return NULL;
    }
    return logInfo;
}
