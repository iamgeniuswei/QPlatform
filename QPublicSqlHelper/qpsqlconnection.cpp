/*
 * Modify date: 2016-07-25 15:28
 * Modify purpose: Add functions
 * Modify Details:
 * 1) apply QPSqlConnection to Singleton pattern.
 * 2) modify close database connection function.
 * 3) add destroy database connection.
 * 4) add open database connection.
 */



#include "qpsqlconnection.h"
#include "private/qpsqlconnection_p.h"
#include <QString>
#include <QSqlDatabase>
#include <QSqlError>
#include "sqlerror.h"
QPSqlConnection *QPSqlConnection::_instance = nullptr;
QPSqlConnection ::GarbageCollection QPSqlConnection::gc;
QMutex QPSqlConnection::mutex;

QPSqlConnection::QPSqlConnection():d_ptr(new QPSqlConnectionPrivate(this))
{

}

QPSqlConnection::~QPSqlConnection()
{
    delete d_ptr;
    d_ptr = nullptr;
}

QPSqlConnection *QPSqlConnection::getInstance()
{
    if(_instance == nullptr)
    {
        mutex.lock();
        if(_instance == nullptr)
            _instance = new (std::nothrow) QPSqlConnection;
        mutex.unlock();
    }
    return _instance;
}

void QPSqlConnection::initializeConnection(const QString &driver, const QString &hostName, int port, const QString &dbName, const QString &userName, const QString &password, const QString &connName)
{
    Q_D(QPSqlConnection);
    d->_driver = driver;
    d->_hostName = hostName;
    d->_port = port;
    d->_dbName = dbName;
    d->_userName = userName;
    d->_password = password;
    d->_connName = connName;
}

bool QPSqlConnection::connectToDefaultDB(const QString &driver, const QString &hostName, const int port, const QString &databaseName, const QString &userName, const QString &password)
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
        return false;
    }
}

bool QPSqlConnection::connectToNameDB(const QString &driver, const QString &connName, const QString &hostName, const int port, const QString &databaseName, const QString &userName, const QString &password)
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
        return false;
    }
}

QSqlDatabase QPSqlConnection::getDefaultDB()
{
    return QSqlDatabase::database();
}

QSqlDatabase QPSqlConnection::getNameDB(const QString &connName)
{
    return QSqlDatabase::database(connName);
}

bool QPSqlConnection::openDefaultDB()
{
    QSqlDatabase db = QSqlDatabase::database();
    return db.isOpen();
}

bool QPSqlConnection::openNameDB(const QString &connName)
{
    QSqlDatabase db = QSqlDatabase::database(connName);
    return db.isOpen();
}

bool QPSqlConnection::closeDefaultDB()
{
    QSqlDatabase db = QSqlDatabase::database();
    db.close();
    return !db.isOpen();
}

bool QPSqlConnection::closeNameDB(const QString &connName)
{
    QSqlDatabase db = QSqlDatabase::database(connName);
    db.close();
    return !db.isOpen();
}

bool QPSqlConnection::destroyDefaultDB()
{
    QSqlDatabase db = QSqlDatabase::database();
    db.close();
    QSqlDatabase::removeDatabase(db.connectionName());
    return !db.isValid();
}

bool QPSqlConnection::destroyNameDB(const QString &connName)
{
    QSqlDatabase db = QSqlDatabase::database(connName);
    db.close();
    QSqlDatabase::removeDatabase(connName);
    return !db.isValid();
}

void QPSqlConnection::setError(int errNo, const QString &errMsg)
{
    QPErrorInfo *info = new (std::nothrow) QPErrorInfo;
    if(info)
    {
        info->setErrorNo(errNo);
        info->setErrorMsg(errMsg);
        QPErrorInfoQueue *queue = QPErrorInfoQueue::getInstance();
        queue->addErrorInfo(info);
    }
}

