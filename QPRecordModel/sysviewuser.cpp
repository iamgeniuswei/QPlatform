#include "sysviewuser.h"

SysViewUser::SysViewUser()
{
}

int SysViewUser::getUserID() const
{
    return userID;
}

void SysViewUser::setUserID(int value)
{
    userID = value;
}
QString SysViewUser::getUserName() const
{
    return userName;
}

void SysViewUser::setUserName(const QString &value)
{
    userName = value;
}
QString SysViewUser::getUserPwd() const
{
    return userPwd;
}

void SysViewUser::setUserPwd(const QString &value)
{
    userPwd = value;
}
QString SysViewUser::getUserUkey() const
{
    return userUkey;
}

void SysViewUser::setUserUkey(const QString &value)
{
    userUkey = value;
}
QString SysViewUser::getSeatName() const
{
    return seatName;
}

void SysViewUser::setSeatName(const QString &value)
{
    seatName = value;
}
QString SysViewUser::getUserAuthName() const
{
    return userAuthName;
}

void SysViewUser::setUserAuthName(const QString &value)
{
    userAuthName = value;
}
QString SysViewUser::getStatusName() const
{
    return statusName;
}

void SysViewUser::setStatusName(const QString &value)
{
    statusName = value;
}
QString SysViewUser::getUserDescription() const
{
    return userDescription;
}

void SysViewUser::setUserDescription(const QString &value)
{
    userDescription = value;
}
