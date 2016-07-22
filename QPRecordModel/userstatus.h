#ifndef USERSTATUS_H
#define USERSTATUS_H
#include "dbmodel.h"
#include "dbmodel_global.h"
#include <QDateTime>
class DBMODELSHARED_EXPORT UserStatus : public DBModel
{
public:
    UserStatus();

    int id() const;
    void setId(int id);

    int statusID() const;
    void setStatusID(int statusID);

    QDateTime inTime() const;
    void setInTime(const QDateTime &inTime);

    QDateTime outTime() const;
    void setOutTime(const QDateTime &outTime);

private:
    int _id;
    int _statusID;
    QDateTime _inTime;
    QDateTime _outTime;
};

#endif // USERSTATUS_H
