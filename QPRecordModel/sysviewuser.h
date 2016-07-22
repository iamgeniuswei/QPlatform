#ifndef SYSVIEWUSER_H
#define SYSVIEWUSER_H
#include "dbmodel.h"
#include <QString>
class DBMODELSHARED_EXPORT SysViewUser : public DBModel
{
public:
    SysViewUser();
public:

    int getUserID() const;
    void setUserID(int value);

    QString getUserName() const;
    void setUserName(const QString &value);

    QString getUserPwd() const;
    void setUserPwd(const QString &value);

    QString getUserUkey() const;
    void setUserUkey(const QString &value);

    QString getSeatName() const;
    void setSeatName(const QString &value);

    QString getUserAuthName() const;
    void setUserAuthName(const QString &value);

    QString getStatusName() const;
    void setStatusName(const QString &value);

    QString getUserDescription() const;
    void setUserDescription(const QString &value);

private:
    int userID;
    QString userName;
    QString userPwd;
    QString userUkey;
    QString seatName;
    QString userAuthName;
    QString statusName;
    QString userDescription;
};

#endif // SYSVIEWUSER_H
