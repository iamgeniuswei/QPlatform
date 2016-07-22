#include "softwarestatus.h"

SoftwareStatus::SoftwareStatus():
    _id(3), _name(QString()),_seatID(3),_statusID(3),\
    _userID(2),_inTime(QDateTime()),_outTime(QDateTime())
{
}
int SoftwareStatus::id() const
{
    return _id;
}

void SoftwareStatus::setId(int id)
{
    _id = id;
}
QString SoftwareStatus::name() const
{
    return _name;
}

void SoftwareStatus::setName(const QString &name)
{
    _name = name;
}
int SoftwareStatus::seatID() const
{
    return _seatID;
}

void SoftwareStatus::setSeatID(int seatID)
{
    _seatID = seatID;
}
int SoftwareStatus::statusID() const
{
    return _statusID;
}

void SoftwareStatus::setStatusID(int statusID)
{
    _statusID = statusID;
}
int SoftwareStatus::userID() const
{
    return _userID;
}

void SoftwareStatus::setUserID(int userID)
{
    _userID = userID;
}
QDateTime SoftwareStatus::inTime() const
{
    return _inTime;
}

void SoftwareStatus::setInTime(const QDateTime &inTime)
{
    _inTime = inTime;
}
QDateTime SoftwareStatus::outTime() const
{
    return _outTime;
}

void SoftwareStatus::setOutTime(const QDateTime &outTime)
{
    _outTime = outTime;
}







