#include "qpnonquerythread.h"
#include "qpdatamodel.h"
#include "qpdataoperation.h"
#include "sqlobjectfactory.h"
#include <QMutex>
#include <QDebug>

QMutex nonQueryMutex;
QPNonQueryThread::QPNonQueryThread(QObject *parent) :
    QPSqlWorkThread(parent),
    dModel(NULL),
    _tableOperation(QString()),
    _connName(QString())
{
}

void QPNonQueryThread::setNonQueryParameter(const QString &tableName, DBModel * const model)
{
    dModel = model;
    _tableOperation = tableName + "Operation";
}

void QPNonQueryThread::setNonQueryParameter(const QString &tableName, const QString &connName, DBModel * const model)
{
    dModel = model;
    _tableOperation = tableName + "Operation";
    _connName = connName;
}

void QPNonQueryThread::run()
{
    nonQueryMutex.lock();
    qDebug() << sqlWorkMode();
    switch (sqlWorkMode())
    {
    case INSERT:
    {
        QPDataOperation *operation = NULL;
        operation = qobject_cast<QPDataOperation*>(SqlObjectFactory::createObject(_tableOperation));
        if(operation)
        {
            if(_connName.isEmpty())
            {
                int count = operation->InsertRecord(dModel);
                emit sendNonQueryResult(count);
                delete operation;
            }
            else
            {
                int count = operation->InsertRecord(dModel,_connName);
                emit sendNonQueryResult(count);
                delete operation;
            }

        }
        break;
    }

    case DELETE:
    {
        QPDataOperation *operation = NULL;
        operation = qobject_cast<QPDataOperation*>(SqlObjectFactory::createObject(_tableOperation));
        if(operation)
        {
            int count = operation->DeleteRecord(dModel, _connName);
            emit sendNonQueryResult(count);
            delete operation;
        }
        break;
    }

    case UPDATE:
    {
        QPDataOperation *operation = NULL;
        operation = qobject_cast<QPDataOperation*>(SqlObjectFactory::createObject(_tableOperation));
        if(operation)
        {
            int count = operation->UpdateRecord(dModel, _connName);
            emit sendNonQueryResult(count);
            delete operation;
        }
        break;
    }
    default:
        break;
    }
    nonQueryMutex.unlock();
}
