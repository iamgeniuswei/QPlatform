#ifndef SQLCONNECTION_H
#define SQLCONNECTION_H
#include "sqlhelper_global.h"
#include <QMutex>
class QSqlDatabase;
class QPSqlConnectionPrivate;
class SQLHELPEREXPORT QPSqlConnection
{
private:
    QPSqlConnection();
    ~QPSqlConnection();
    QPSqlConnection(const QPSqlConnection&);
    QPSqlConnection& operator =(const QPSqlConnection&);
    static QPSqlConnection *_instance;

    class GarbageCollection
    {
    public:
        ~GarbageCollection()
        {
            if(_instance != nullptr)
            {
                delete _instance;
                _instance = nullptr;
            }
        }
    };

    static GarbageCollection gc;
    static QMutex mutex;

public:
    static QPSqlConnection *getInstance();
    void initializeConnection(const QString &driver,\
                              const QString &hostName,\
                              int port,\
                              const QString &dbName,\
                              const QString &userName,\
                              const QString &password,\
                              const QString &connName);
    bool connectToDefaultDB(const QString& driver,\
                                 const QString& hostName,\
                                 const int port,\
                                 const QString& databaseName,\
                                 const QString& userName,\
                                 const QString& password);
    bool connectToNameDB(const QString& driver,\
                                const QString& connName,\
                                 const QString& hostName,\
                                 const int port,\
                                 const QString& databaseName,\
                                 const QString& userName,\
                                 const QString& password);
    static QSqlDatabase getDefaultDB();
    static QSqlDatabase getNameDB(const QString& connName);

    bool openDefaultDB();
    bool openNameDB(const QString &connName);

    bool closeDefaultDB();
    bool closeNameDB(const QString& connName);

    bool destroyDefaultDB();
    bool destroyNameDB(const QString &connName);

private:
    void setError(int errNo, const QString& errMsg);
private:
    QPSqlConnectionPrivate * d_ptr;
    Q_DECLARE_PRIVATE(QPSqlConnection)
};

#endif // SQLCONNECTION_H
