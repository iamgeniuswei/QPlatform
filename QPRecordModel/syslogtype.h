#ifndef SYSLOGTYPE_H
#define SYSLOGTYPE_H

#include "dbmodel_global.h"
#include "dbmodel.h"
#include <QString>

class DBMODELSHARED_EXPORT SysLogType : public DBModel
{
public:
    int getLogTypeId() const;
    void setLogTypeId(int value);

    QString getLogTypeName() const;
    void setLogTypeName(const QString &value);

    QString getLogTypeDescription() const;
    void setLogTypeDescription(const QString &value);

private:
    int logTypeId;
    QString logTypeName;
    QString logTypeDescription;

};

#endif // SYSLOGTYPE_H
