#include "qpnodeattribute.h"

QPNodeAttribute::QPNodeAttribute()
{
}
NODETYPE QPNodeAttribute::getType() const
{
    return type;
}

void QPNodeAttribute::setType(const NODETYPE &value)
{
    type = value;
}
QString QPNodeAttribute::getTypeName() const
{
    return typeName;
}

void QPNodeAttribute::setTypeName(const QString &value)
{
    typeName = value;
}
QString QPNodeAttribute::getModel() const
{
    return model;
}

void QPNodeAttribute::setModel(const QString &value)
{
    model = value;
}
QString QPNodeAttribute::getSerialN() const
{
    return serialN;
}

void QPNodeAttribute::setSerialN(const QString &value)
{
    serialN = value;
}
QString QPNodeAttribute::getInnerN() const
{
    return innerN;
}

void QPNodeAttribute::setInnerN(const QString &value)
{
    innerN = value;
}
QString QPNodeAttribute::getDeploy() const
{
    return deploy;
}

void QPNodeAttribute::setDeploy(const QString &value)
{
    deploy = value;
}
NODESTATUS QPNodeAttribute::getStatus() const
{
    return status;
}

void QPNodeAttribute::setStatus(const NODESTATUS &value)
{
    status = value;
}







