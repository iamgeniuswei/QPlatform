#include "userstatus.h"

UserStatus::UserStatus():
    _id(2)
{
}
int UserStatus::id() const
{
    return _id;
}

void UserStatus::setId(int id)
{
    _id = id;
}
int UserStatus::statusID() const
{
    return _statusID;
}

void UserStatus::setStatusID(int statusID)
{
    _statusID = statusID;
}
QDateTime UserStatus::inTime() const
{
    return _inTime;
}

void UserStatus::setInTime(const QDateTime &inTime)
{
    _inTime = inTime;
}
QDateTime UserStatus::outTime() const
{
    return _outTime;
}

void UserStatus::setOutTime(const QDateTime &outTime)
{
    _outTime = outTime;
}




