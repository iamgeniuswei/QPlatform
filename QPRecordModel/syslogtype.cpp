#include "syslogtype.h"

int SysLogType::getLogTypeId() const
{
    return logTypeId;
}

void SysLogType::setLogTypeId(int value)
{
    logTypeId = value;
}
QString SysLogType::getLogTypeName() const
{
    return logTypeName;
}

void SysLogType::setLogTypeName(const QString &value)
{
    logTypeName = value;
}
QString SysLogType::getLogTypeDescription() const
{
    return logTypeDescription;
}

void SysLogType::setLogTypeDescription(const QString &value)
{
    logTypeDescription = value;
}


