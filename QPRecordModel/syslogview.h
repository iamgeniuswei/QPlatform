#ifndef SYSLOGVIEW_H
#define SYSLOGVIEW_H

#include "dbmodel_global.h"
#include "dbmodel.h"
#include <QDateTime>

class DBMODELSHARED_EXPORT SysLogView : public DBModel
{

public:
    int getLogId() const;
    void setLogId(int value);

    int getTypeId() const;
    void setTypeId(int value);

    QString getLogDetail() const;
    void setLogDetail(const QString &value);

    QDateTime getLogOperateTime() const;
    void setLogOperateTime(const QDateTime &value);

    int getUserId() const;
    void setUserId(int value);

    int getUserAuthority() const;
    void setUserAuthority(int value);

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

    int getLogTypeId() const;
    void setLogTypeId(int value);

    QString getLogTypeName() const;
    void setLogTypeName(const QString &value);

    QString getLogTypeDescription() const;
    void setLogTypeDescription(const QString &value);

    QString getLogUserName() const;
    void setLogUserName(const QString &value);

private:
    int logId;
    QString logUserName;
    int typeId;
    QString logDetail;
    QDateTime logOperateTime;
    int userId;
    int userAuthority;
    QString userName;
    QString userPwd;
    QString userUkey;
    QString userHostip;
    int userStatus;
    QString userDescription;
    int logTypeId;
    QString logTypeName;
    QString logTypeDescription;

};

#endif // SYSLOGVIEW_H
