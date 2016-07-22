#include "sysuser.h"

int SysUser::getUserId() const
{
    return userId;
}

void SysUser::setUserId(int value)
{
    userId = value;
}

QString SysUser::getUserName() const
{
    return userName;
}

void SysUser::setUserName(const QString &value)
{
    userName = value;
}
QString SysUser::getUserPwd() const
{
    return userPwd;
}

void SysUser::setUserPwd(const QString &value)
{
    userPwd = value;
}
QString SysUser::getUserUkey() const
{
    return userUkey;
}

void SysUser::setUserUkey(const QString &value)
{
    userUkey = value;
}

QString SysUser::getUserDescription() const
{
    return userDescription;
}

void SysUser::setUserDescription(const QString &value)
{
    userDescription = value;
}
int SysUser::getUserSeat() const
{
    return userSeat;
}

void SysUser::setUserSeat(int value)
{
    userSeat = value;
}
int SysUser::getUserAuth() const
{
    return userAuth;
}

void SysUser::setUserAuth(int value)
{
    userAuth = value;
}









