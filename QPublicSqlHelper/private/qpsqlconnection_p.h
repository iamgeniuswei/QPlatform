#ifndef QPSQLCONNECTION_P_H
#define QPSQLCONNECTION_P_H
#include <QObject>
class QPSqlConnection;
class QPSqlConnectionPrivate
{
    Q_DECLARE_PUBLIC(QPSqlConnection)
public:
    QPSqlConnectionPrivate(QPSqlConnection *parent)
        :q_ptr(parent), _port(0)
    {}
public:
    QString _driver;
    QString _connName;
    QString _hostName;
    unsigned short _port;
    QString _dbName;
    QString _userName;
    QString _password;
private:
    QPSqlConnection *const q_ptr;
};
#endif // QPSQLCONNECTION_P_H
