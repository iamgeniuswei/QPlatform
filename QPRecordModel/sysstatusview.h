#ifndef SYSSTATUSVIEW_H
#define SYSSTATUSVIEW_H

#include "dbmodel_global.h"
#include "dbmodel.h"
#include <QString>
class DBMODELSHARED_EXPORT SysStatusView : public DBModel
{
public:
    int getUserId() const;
    void setUserId(int value);

    int getUserSeat() const;
    void setUserSeat(int value);

    QString getUserName() const;
    void setUserName(const QString &value);

    QString getUserPwd() const;
    void setUserPwd(const QString &value);

    QString getUserUkey() const;
    void setUserUkey(const QString &value);

    QString getUserHostip() const;
    void setUserHostip(const QString &value);

    int getUserStatus() const;
    void setUserStatus(int value);

    QString getUserDescription() const;
    void setUserDescription(const QString &value);

    int getStatustypeId() const;
    void setStatustypeId(int value);

    int getStatustypeSeatid() const;
    void setStatustypeSeatid(int value);

    QString getStatustypeName() const;
    void setStatustypeName(const QString &value);

    int getStatustypeOrder() const;
    void setStatustypeOrder(int value);

    QString getStatustypeDescription() const;
    void setStatustypeDescription(const QString &value);

private:
    int userId;
    int userSeat;
    QString userName;
    QString userPwd;
    QString userUkey;
    QString userHostip;
    int userStatus;
    QString userDescription;
    int statustypeId;
    int statustypeSeatid;
    QString statustypeName;
    int statustypeOrder;
    QString statustypeDescription;

};

#endif // SYSSTATUSVIEW_H
