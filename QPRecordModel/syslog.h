#ifndef SYSLOG_H
#define SYSLOG_H

#include "dbmodel_global.h"
#include "dbmodel.h"
#include <QString>
#include <QDateTime>

class DBMODELSHARED_EXPORT SysLog : public DBModel
{
public:
    int getLogId() const;
    void setLogId(int value);


    int getLogTypeId() const;
    void setLogTypeId(int value);

    QString getLogDetail() const;
    void setLogDetail(const QString &value);

    QDateTime getLogOperateTime() const;
    void setLogOperateTime(const QDateTime &value);


    int getLogUserID() const;
    void setLogUserID(int value);

private:
    int logId;
    int logUserID;
    int logTypeId;
    QString logDetail;
    QDateTime logOperateTime;
};

#endif // SYSLOG_H
