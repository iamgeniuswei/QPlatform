#ifndef SYSUSER_H
#define SYSUSER_H

#include "dbmodel_global.h"
#include "dbmodel.h"
#include <QString>

class DBMODELSHARED_EXPORT SysUser : public DBModel
{
public:
    int getUserId() const;
    void setUserId(int value);

    QString getUserName() const;
    void setUserName(const QString &value);

    QString getUserPwd() const;
    void setUserPwd(const QString &value);

    QString getUserUkey() const;
    void setUserUkey(const QString &value);

    QString getUserDescription() const;
    void setUserDescription(const QString &value);

    int getUserSeat() const;
    void setUserSeat(int value);

    int getUserAuth() const;
    void setUserAuth(int value);

private:
    int userId;
    int userSeat;
    QString userName;
    QString userPwd;
    QString userUkey;
    int userAuth;
    QString userDescription;
};

#endif // SYSUSER_H
