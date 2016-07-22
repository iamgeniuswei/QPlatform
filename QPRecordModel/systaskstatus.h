#ifndef SYSTASKSTATUS_H
#define SYSTASKSTATUS_H

#include "dbmodel_global.h"
#include "dbmodel.h"
#include <QString>
#include <QDateTime>

class DBMODELSHARED_EXPORT SysTaskStatus : public DBModel
{
public:
    int getStatusId() const;
    void setStatusId(int value);

    int getStatusOriginid() const;
    void setStatusOriginid(int value);

    int getStatusTypeid() const;
    void setStatusTypeid(int value);

    QString getStatusReporter() const;
    void setStatusReporter(const QString &value);

    int getStatusIsfinished() const;
    void setStatusIsfinished(int value);

    QDateTime getStatusFinishedtime() const;
    void setStatusFinishedtime(const QDateTime &value);

    QString getStatusDescription() const;
    void setStatusDescription(const QString &value);

private:
    int statusId;
    int statusOriginid;
    int statusTypeid;
    QString statusReporter;
    int statusIsfinished;
    QDateTime statusFinishedtime;
    QString statusDescription;
};

#endif // SYSTASKSTATUS_H
