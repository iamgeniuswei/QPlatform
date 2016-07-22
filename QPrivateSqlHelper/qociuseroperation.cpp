#include "qociuseroperation.h"
#include "sysuser.h"
#include <QSqlQuery>
#include <QVariant>
#include <QSqlError>
#include <QDebug>
#include "sqlerror.h"
#include "qpsqlconnection.h"
QOCIUserOperation::QOCIUserOperation(QObject *parent)
    :QPOCIDataOperation(parent)
{
    setTableName("T_USER");
}

DBModel *QOCIUserOperation::QueryRecord(const QString &condition)
{
    SysUser *user = new SysUser;
    if(!condition.isEmpty())
    {
        QString sql = "SELECT * FROM T_USER where " + condition;
        QSqlQuery query(sql);
        //if query success, only one row
        if(!(query.lastError().isValid()) && query.next())
        {
            qDebug() << query.isValid();
            user->setUserId(query.value("USER_ID").toInt());
            user->setUserSeat(query.value("USER_SEAT").toInt());
            user->setUserName(query.value("USER_NAME").toString());
            user->setUserPwd(query.value("USER_PWD").toString());
            user->setUserUkey(query.value("USER_UKEY").toString());
            user->setUserDescription(query.value("USER_DESCRIPTION").toString());
            user->setUserAuth(query.value("USER_AUTH").toInt());
        }
        else
        {
            QPErrorInfoQueue *queue = QPErrorInfoQueue::getInstance();
            queue->addErrorInfo(SqlError::errNo_NoRecord, query.lastError().text());
            return NULL;
        }
    }
    else
    {
        QString sql = "SELECT * FROM T_USER";
        QSqlQuery query(sql);
        //if query success, only one row
        if(!(query.lastError().isValid()) && query.next())
        {
            qDebug() << query.isValid();
            user->setUserId(query.value("USER_ID").toInt());
            user->setUserSeat(query.value("USER_SEAT").toInt());
            user->setUserName(query.value("USER_NAME").toString());
            user->setUserPwd(query.value("USER_PWD").toString());
            user->setUserUkey(query.value("USER_UKEY").toString());
            user->setUserDescription(query.value("USER_DESCRIPTION").toString());
            user->setUserAuth(query.value("USER_AUTH").toInt());
        }
        else
        {
            QPErrorInfo info;
            info.setErrorNo(SqlError::errNo_NoRecord);
            info.setErrorMsg(query.lastError().text());
            QPErrorInfoQueue *queue = QPErrorInfoQueue::getInstance();
            queue->addErrorInfo(info);
            return NULL;
        }
    }

    return user;
}

DBModel *QOCIUserOperation::QueryRecord(const QString &condition, const QString &connName)
{
    SysUser *user = new SysUser;
    QString sql;
    if(!condition.isEmpty())
    {
        sql = "SELECT * FROM T_USER WHERE " + condition;
    }
    else
        sql = "SELECT * FROM T_USER";

    if(!connName.isEmpty())
    {
        QSqlDatabase db = QPSqlConnection::getDBbyName("TaskDB");
        QSqlQuery query(sql, db);
        //if query success, only one row
        if(!(query.lastError().isValid()) && query.next())
        {
            qDebug() << query.isValid();
            user->setUserId(query.value("USER_ID").toInt());
            user->setUserSeat(query.value("USER_SEAT").toInt());
            user->setUserName(query.value("USER_NAME").toString());
            user->setUserPwd(query.value("USER_PWD").toString());
            user->setUserUkey(query.value("USER_UKEY").toString());
            user->setUserDescription(query.value("USER_DESCRIPTION").toString());
            user->setUserAuth(query.value("USER_AUTH").toInt());
        }
        else
        {
            QPErrorInfo info;
            info.setErrorNo(SqlError::errNo_NoRecord);
            info.setErrorMsg(query.lastError().text());
            QPErrorInfoQueue *queue = QPErrorInfoQueue::getInstance();
            queue->addErrorInfo(info);
            return NULL;
        }
        return user;
    }
    else
    {
        return QueryRecord(condition);
    }

}
