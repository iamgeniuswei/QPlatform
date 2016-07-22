#include "qpsqlcommand.h"
#include "sqlerror.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlDatabase>
#include "qpsqlconnection.h"
#include "qpquerymodel.h"

QPSqlCommand::QPSqlCommand()
{
}

int QPSqlCommand::execNoQuerySQL(const QString &sql, const QString &connName)
{
    if(!sql.isEmpty())
    {
        if(connName.isEmpty())
        {
            QSqlQuery query;
            if(query.exec(sql))
            {
                int insertRows = query.numRowsAffected();
                return insertRows;
            }
            else
            {
                QPErrorInfoQueue *queue = QPErrorInfoQueue::getInstance();
                queue->addErrorInfo(SqlError::errNo_QueryExecError, query.lastError().text());
                return SqlError::retInsertRecordError;
            }
        }
        else
        {
            QSqlDatabase db = QPSqlConnection::getDBbyName(connName);
            QSqlQuery query(db);
            if(query.exec(sql))
            {
                int insertRows = query.numRowsAffected();
                return insertRows;
            }
            else
            {
                QPErrorInfoQueue *queue = QPErrorInfoQueue::getInstance();
                queue->addErrorInfo(SqlError::errNo_QueryExecError, query.lastError().text());
                return SqlError::retInsertRecordError;
            }
        }
    }
    else
    {
        QPErrorInfoQueue *queue = QPErrorInfoQueue::getInstance();
        queue->addErrorInfo(SqlError::errNo_SqlIsEmpty, SqlError::errStr_SqlIsEmpty);
        return SqlError::retInsertRecordError;
    }
}

int QPSqlCommand::execQSqlQuery(QSqlQuery &query)
{
    if(query.exec())
    {
        int rowsAffected = query.numRowsAffected();
        return rowsAffected;
    }
    else
    {
        QPErrorInfoQueue *queue = QPErrorInfoQueue::getInstance();
        queue->addErrorInfo(SqlError::errNo_QueryExecError, query.lastError().text());
        return SqlError::retInsertRecordError;
    }
}

bool QPSqlCommand::queryModel(QPQueryModel *model, const QString &sql, const QString &connName)
{
    if(model)
    {
        if(!connName.isEmpty())
        {
            QSqlDatabase db = QPSqlConnection::getDBbyName(connName);
            model->setQuery(sql, db);
            if(model->lastError().isValid())
            {
                QPErrorInfoQueue *queue = QPErrorInfoQueue::getInstance();
                queue->addErrorInfo(SqlError::errNo_ModelQueryError, model->lastError().text());
                return SqlError::retNO_FAIL;
            }
        }
        else
        {
            queryModel(model, sql);
        }
    }
    else
    {
        QPErrorInfoQueue *queue = QPErrorInfoQueue::getInstance();
        queue->addErrorInfo(SqlError::errNo_PointIsNULL, SqlError::errStr_PointIsNull);
        return SqlError::retNO_FAIL;
    }
    return SqlError::retNO_SUCCESS;
}

bool QPSqlCommand::queryModel(QPQueryModel *model, const QString &sql)
{
    if(model)
    {
        model->setQuery(sql);
        if(model->lastError().isValid())
        {
            QPErrorInfoQueue *queue = QPErrorInfoQueue::getInstance();
            queue->addErrorInfo(SqlError::errNo_ModelQueryError, model->lastError().text());
            return SqlError::retNO_FAIL;
        }
    }
    else
    {
        QPErrorInfoQueue *queue = QPErrorInfoQueue::getInstance();
        queue->addErrorInfo(SqlError::errNo_PointIsNULL, SqlError::errStr_PointIsNull);
        return SqlError::retNO_FAIL;
    }
    return SqlError::retNO_SUCCESS;
}

int QPSqlCommand::queryCount(const QString &tableName, const QString &condition) const
{
    QString sql = "SELECT COUNT(*) FROM " + tableName;
    if(!condition.isEmpty())
    {
        sql += " WHERE " + condition;
    }
    QSqlQuery query;
    if(query.exec(sql))
    {
        if(query.next())
        {
            return query.value(0).toInt();
        }
        else
        {
            QPErrorInfoQueue *queue = QPErrorInfoQueue::getInstance();
            queue->addErrorInfo(SqlError::errNo_ModelQueryError, query.lastError().text());
            return SqlError::retNO_ERROR;
        }
    }
    else
    {
        QPErrorInfoQueue *queue = QPErrorInfoQueue::getInstance();
        queue->addErrorInfo(SqlError::errNo_ModelQueryError, query.lastError().text());
        return SqlError::retNO_ERROR;
    }
}

int QPSqlCommand::queryCount(const QString &tableName, const QString &condition, const QString &connName) const
{

    QString sql = "SELECT COUNT(*) FROM " + tableName;
    if(!condition.isEmpty())
    {
        sql += " WHERE " + condition;
    }
    if(connName.isEmpty())
    {
        return queryCount(tableName, condition);
    }
    else
    {
        QSqlDatabase db = QPSqlConnection::getDBbyName(connName);
        QSqlQuery query(db);
        if(query.exec(sql))
        {
            if(query.next())
            {
                return query.value(0).toInt();
            }
            else
            {
                QPErrorInfoQueue *queue = QPErrorInfoQueue::getInstance();
                queue->addErrorInfo(SqlError::errNo_ModelQueryError, query.lastError().text());
                return SqlError::retNO_ERROR;
            }
        }
        else
        {

            QPErrorInfoQueue *queue = QPErrorInfoQueue::getInstance();
            queue->addErrorInfo(SqlError::errNo_ModelQueryError, query.lastError().text());
            return SqlError::retNO_ERROR;
        }
    }
}

