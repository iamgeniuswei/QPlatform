#ifndef SOFTWARESTATUS_H
#define SOFTWARESTATUS_H
#include <QString>
#include <QDateTime>
#include "dbmodel.h"
#include "dbmodel_global.h"
class DBMODELSHARED_EXPORT SoftwareStatus : public DBModel
{
public:
    SoftwareStatus();

    int id() const;
    void setId(int id);

    QString name() const;
    void setName(const QString &name);

    int seatID() const;
    void setSeatID(int seatID);

    int statusID() const;
    void setStatusID(int statusID);

    int userID() const;
    void setUserID(int userID);

    QDateTime inTime() const;
    void setInTime(const QDateTime &inTime);

    QDateTime outTime() const;
    void setOutTime(const QDateTime &outTime);

private:
    int _id;
    QString _name;
    int _seatID;
    int _statusID;
    int _userID;
    QDateTime _inTime;
    QDateTime _outTime;

};

#endif // SOFTWARESTATUS_H
