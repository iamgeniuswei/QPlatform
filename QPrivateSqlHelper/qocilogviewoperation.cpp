#include "qocilogviewoperation.h"
#include "qpsqlcommand.h"
#include "qpocisqlcommand.h"
#include "sqlerror.h"
#include "syslogview.h"
#include <QSqlQuery>
#include <QVariant>

QOCILogViewOperation::QOCILogViewOperation(QObject *parent)
    :QPOCIDataOperation(parent)
{
    setTableName("VIEW_LOG");
}

DBModel *QOCILogViewOperation::QueryRecord(int _id)
{
    SysLogView *logView = new SysLogView;
    QString sql = "SELECT * FROM VIEW_LOG where LOG_ID =" + QString::number(_id,10);
    QSqlQuery query(sql);
    //if query success, only one row
    if(!(query.lastError().isValid()) && query.next())
    {
        logView->setLogId(query.value("LOG_ID").toInt());
        logView->setLogUserName(query.value("LOG_USERNAME").toString());
        logView->setTypeId(query.value("LOGTYPE_ID").toInt());
        logView->setLogDetail(query.value("LOG_DETAIL").toString());
        logView->setLogOperateTime(query.value("LOG_OPERATETIME").toDateTime());
        logView->setUserId(query.value("USER_ID").toInt());
        logView->setUserAuthority(query.value("USER_SEAT").toInt());
        logView->setUserName(query.value("USER_NAME").toString());
        logView->setUserPwd(query.value("USER_PWD").toString());
        logView->setUserUkey(query.value("USER_UKEY").toString());
        logView->setUserHostip(query.value("USER_HOSTIP").toString());
        logView->setUserStatus(query.value("USER_STATUS").toInt());
        logView->setUserDescription(query.value("USER_DESCRIPTION").toString());
        logView->setLogTypeId(query.value("LOGTYPE_ID").toInt());
        logView->setLogTypeName(query.value("LOGTYPE_NAME").toString());
        logView->setLogTypeDescription(query.value("LOGTYPE_DESCRIPTION").toString());
    }
    else
    {
        QPErrorInfoQueue *queue = QPErrorInfoQueue::getInstance();
        queue->addErrorInfo(SqlError::errNo_NoRecord, query.lastError().text());
        return NULL;
    }
    return logView;
}
