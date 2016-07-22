#ifndef SQLCONNECTION_H
#define SQLCONNECTION_H
#include "sqlhelper_global.h"
class QString;
class QSqlDatabase;
class SQLHELPEREXPORT QPSqlConnection
{
public:
    QPSqlConnection();
    ~QPSqlConnection();
    static bool ConnectionToDBByDefault(const QString& driver,\
                                 const QString& hostName,\
                                 const int port,\
                                 const QString& databaseName,\
                                 const QString& userName,\
                                 const QString& password);
    static bool ConnectionToDBByName(const QString& driver,\
                                const QString& connName,\
                                 const QString& hostName,\
                                 const int port,\
                                 const QString& databaseName,\
                                 const QString& userName,\
                                 const QString& password);
    static QSqlDatabase getDefaultDB();
    static QSqlDatabase getDBbyName(const QString& connName);

    static void closeDefaultDB();
    static void clseDBbyName(const QString& connName);
private:

};

#endif // SQLCONNECTION_H
