#include "qpquerythread.h"
#include "qpdataoperation.h"
#include "sqlobjectfactory.h"
#include <QDebug>
#include <QMutex>
#include "sqlerror.h"
#include "qpquerymodel.h"

QMutex qpQueryMutex;

QPQueryThread::QPQueryThread(QObject *parent):QPSqlWorkThread(parent),
    _tableOperation(QString()),
    _queryModel(QString()),
    _connName(QString()),
    _condition(QString()),
    _index(0),
    _step(100),
    _rowId(0)
{
}

void QPQueryThread::setQueryPageParameter(unsigned int index, unsigned int step, const QString &tableName, const QString &condition, const QString &realTable, const QString &connName)
{
    if(!tableName.isEmpty())
    {
        _tableOperation = tableName + "Operation";
        _queryModel = tableName + "QueryModel";
    }
    _index = index;
    _step = step;
    if(!condition.isEmpty())
        _condition = condition;
    if(!realTable.isEmpty())
        _realTable = realTable;
    if(!connName.isEmpty())
        _connName = connName;
}

void QPQueryThread::setQueryCountParameter(const QString &tableName, const QString &condition, const QString &realTable, const QString &connName)
{
    if(!tableName.isEmpty())
        _tableOperation = tableName + "Operation";
    if(!condition.isEmpty())
        _condition = condition;
    if(!realTable.isEmpty())
        _realTable = realTable;
    if(!connName.isEmpty())
        _connName = connName;
}

void QPQueryThread::setQueryRowParameter(const unsigned int _id, const QString &tableName, const QString &connName)
{
    _rowId = _id;
    if(!tableName.isEmpty())
        _tableOperation = tableName + "Operation";
    if(!connName.isEmpty())
        _connName = connName;
}

void QPQueryThread::setQueryRowParameter(const QString &conditon, const QString &tableName, const QString &connName)
{
    if(!conditon.isEmpty())
        _condition = conditon;
    if(!tableName.isEmpty())
        _tableOperation = tableName + "Operation";
    if(!connName.isEmpty())
        _connName = connName;
}

void QPQueryThread::run()
{
    qpQueryMutex.lock();
    switch (sqlWorkMode()) {
    case QUERYPAGE:
    {
        queryPage();
        break;
    }

    case QUERYCOUNT:
    {
        queryCount();
        break;
    }

    case QUERYROW:
    {
        queryRow();
        break;
    }
    case QUERYROWBYCONDITION:
    {
        queryRowByCondition();
        break;
    }

    case QUERYLIST:
    {
        queryList();
        break;
    }

    default:
        break;
    }
    qpQueryMutex.unlock();
}

void QPQueryThread::queryPage()
{
    if(!_tableOperation.isEmpty())
    {
        QPDataOperation *operation = qobject_cast<QPDataOperation*>(SqlObjectFactory::createObject(_tableOperation));
        QPQueryModel *queryModel = qobject_cast<QPQueryModel*>(SqlObjectFactory::createModelObject(_queryModel));
        if(!queryModel)
            queryModel = new QPQueryModel;
        if(operation && queryModel)
        {
            if(!_realTable.isEmpty())
                operation->setTableName(_realTable);
            if(!operation->QueryPage(queryModel, _index, _step, _condition, _connName))
            {
                delete queryModel;
                queryModel = NULL;
            }
            delete operation;
            operation = NULL;

            if(queryModel)
                emit sendQueryPageResult(queryModel);
            else
                emit sendErrorMsg();
        }
        else
        {
            QPErrorInfoQueue *queue = QPErrorInfoQueue::getInstance();
            queue->addErrorInfo(SqlError::errNo_ObjectIsNull, SqlError::errStr_ObjectIsNull);
            emit sendErrorMsg();
        }
    }
    else
    {
        QPErrorInfoQueue *queue = QPErrorInfoQueue::getInstance();
        queue->addErrorInfo(SqlError::errNo_TableIsNULL, SqlError::errStr_TableIsNull);
        emit sendErrorMsg();
    }
}

void QPQueryThread::queryCount()
{
    if(!_tableOperation.isEmpty())
    {
        QPDataOperation *operation = qobject_cast<QPDataOperation*>(SqlObjectFactory::createObject(_tableOperation));
        int count = 0;
        if(operation)
        {
            if(!_realTable.isEmpty())
                operation->setTableName(_realTable);
            count = operation->QueryCount(_condition, _connName);
            if(count != SqlError::retNO_ERROR)
                emit sendQueryCountResult(count);
            else
                emit sendErrorMsg();
            delete operation;
        }
        else
        {
            QPErrorInfoQueue *queue = QPErrorInfoQueue::getInstance();
            queue->addErrorInfo(SqlError::errNo_ObjectIsNull, SqlError::errStr_ObjectIsNull);
            emit sendErrorMsg();
        }
    }
    else
    {
        QPErrorInfoQueue *queue = QPErrorInfoQueue::getInstance();
        queue->addErrorInfo(SqlError::errNo_TableIsNULL, SqlError::errStr_TableIsNull);
        emit sendErrorMsg();
    }
}

void QPQueryThread::queryRow()
{
    QPDataOperation *operation = qobject_cast<QPDataOperation*>(SqlObjectFactory::createObject(_tableOperation));
    DBModel *model = NULL;
    if(operation)
    {
        model = operation->QueryRecord(_rowId, _connName);
        delete operation;
    }
    emit sendQueryRowResult(model);
}

void QPQueryThread::queryRowByCondition()
{
    QPDataOperation *operation = qobject_cast<QPDataOperation*>(SqlObjectFactory::createObject(_tableOperation));
    DBModel *model = NULL;
    if(operation)
    {
        model = operation->QueryRecord(_condition, _connName);
        delete operation;
    }
    emit sendQueryRowResult(model);
}

void QPQueryThread::queryList()
{
    QPDataOperation *operation = qobject_cast<QPDataOperation*>(SqlObjectFactory::createObject(_tableOperation));
    QStringList recordList;
    if(operation)
    {
        recordList = operation->QueryRecordList(QString(), _connName);

        delete operation;
    }
    emit sendQueryListResult(recordList);
}
