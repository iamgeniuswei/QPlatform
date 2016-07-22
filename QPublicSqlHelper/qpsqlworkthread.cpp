#include "qpsqlworkthread.h"

QPSqlWorkThread::QPSqlWorkThread(QObject *parent) :
    QThread(parent)
{
}

QPSqlWorkThread::~QPSqlWorkThread()
{

}

void QPSqlWorkThread::setQueryPageParameter(unsigned int index, unsigned int step, const QString &tableName, const QString &condition, const QString &realTable, const QString &connName)
{
    Q_UNUSED(index);
    Q_UNUSED(step);
    Q_UNUSED(tableName);
    Q_UNUSED(condition);
    Q_UNUSED(realTable);
    Q_UNUSED(connName);
}

//void SqlWorkThread::setQueryPageParameter(unsigned int index, unsigned int step, const QString &tableName, const QString &connName)
//{
//    Q_UNUSED(index);
//    Q_UNUSED(step);
//    Q_UNUSED(tableName);
//    Q_UNUSED(connName);
//}


//void SqlWorkThread::setQueryPageParameter(unsigned int index, unsigned int step, const QString &tableName)
//{
//    Q_UNUSED(index);
//    Q_UNUSED(step);
//    Q_UNUSED(tableName);
//}

//void SqlWorkThread::setQueryPageParameter(unsigned int index, unsigned int step, const QString &tableName, const QString &condition)
//{
//    Q_UNUSED(index);
//    Q_UNUSED(step);
//    Q_UNUSED(tableName);
//    Q_UNUSED(condition);
//}

//void SqlWorkThread::setQueryCountParameterWithConnection(const QString &tableName, const QString &condition, const QString &connName)
//{
//    Q_UNUSED(tableName);
//    Q_UNUSED(condition);
//    Q_UNUSED(connName);
//}

//void SqlWorkThread::setQueryCountParameterWithConnection(const QString &tableName, const QString &connName)
//{
//    Q_UNUSED(tableName);
//    Q_UNUSED(connName);
//}

//void SqlWorkThread::setQueryCountParameter(const QString &tableName)
//{
//    Q_UNUSED(tableName);
//}


void QPSqlWorkThread::setQueryCountParameter(const QString &tableName, const QString &condition, const QString &realTable, const QString &connName)
{
    Q_UNUSED(tableName);
    Q_UNUSED(condition);
    Q_UNUSED(realTable);
    Q_UNUSED(connName);
}

void QPSqlWorkThread::setQueryRowParameter(const unsigned int _id, const QString &tableName, const QString &connName)
{
    Q_UNUSED(tableName);
    Q_UNUSED(_id);
    Q_UNUSED(connName);
}

void QPSqlWorkThread::setQueryRowParameter(const QString &condition, const QString &tableName, const QString &connName)
{
    Q_UNUSED(tableName);
    Q_UNUSED(condition);
    Q_UNUSED(connName);
}

void QPSqlWorkThread::setNonQueryParameter(const QString &tableName, DBModel * const model)
{
    Q_UNUSED(tableName);
    Q_UNUSED(model);
}

void QPSqlWorkThread::setNonQueryParameter(const QString &tableName, const QString &connName, DBModel * const model)
{
    Q_UNUSED(tableName);
    Q_UNUSED(model);
    Q_UNUSED(connName);
}


QPSqlWorkThread::SQLWORKMODE QPSqlWorkThread::sqlWorkMode() const
{
    return _workmode;
}

void QPSqlWorkThread::setSqlWorkMode(QPSqlWorkThread::SQLWORKMODE mode)
{
    _workmode = mode;
}
