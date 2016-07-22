#include "qpsqlconnection.h"
#include <QString>
#include <QSqlDatabase>
#include <QSqlError>
#include "sqlerror.h"
QPSqlConnection::QPSqlConnection()
{

}

QPSqlConnection::~QPSqlConnection()
{

}

bool QPSqlConnection::ConnectionToDBByDefault(const QString &driver, const QString &hostName, const int port, const QString &databaseName, const QString &userName, const QString &password)
{
    QSqlDatabase db = QSqlDatabase::addDatabase(driver);
    db.setHostName(hostName);
    db.setPort(port);
    db.setDatabaseName(databaseName);
    db.setUserName(userName);
    db.setPassword(password);
    if(db.open())
        return true;
    else
    {

        QPErrorInfo info;
        info.setErrorNo(SqlError::errNo_ConneciontError);
        info.setErrorMsg(db.lastError().text());
        QPErrorInfoQueue *queue = QPErrorInfoQueue::getInstance();
        queue->addErrorInfo(info);
        return false;
    }
}

bool QPSqlConnection::ConnectionToDBByName(const QString &driver, const QString &connName, const QString &hostName, const int port, const QString &databaseName, const QString &userName, const QString &password)
{
    QSqlDatabase db = QSqlDatabase::addDatabase(driver,connName);
    db.setHostName(hostName);
    db.setPort(port);
    db.setDatabaseName(databaseName);
    db.setUserName(userName);
    db.setPassword(password);
    if(db.open())
        return true;
    else
    {
        QPErrorInfo info;
        info.setErrorNo(SqlError::errNo_ConneciontError);
        info.setErrorMsg(db.lastError().text());
        QPErrorInfoQueue *queue = QPErrorInfoQueue::getInstance();
        queue->addErrorInfo(info);
        return false;
    }
}

QSqlDatabase QPSqlConnection::getDefaultDB()
{
    return QSqlDatabase::database();
}

QSqlDatabase QPSqlConnection::getDBbyName(const QString &connName)
{
    return QSqlDatabase::database(connName);
}

void QPSqlConnection::closeDefaultDB()
{
    QSqlDatabase db = getDefaultDB();
    QString dbName = db.connectionName();
    db.close();
    db.removeDatabase(dbName);

}

void QPSqlConnection::clseDBbyName(const QString &connName)
{
    QSqlDatabase db = getDBbyName(connName);
    db.close();
    db.removeDatabase(connName);
}

