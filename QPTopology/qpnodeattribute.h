#ifndef DEVICEINFO_H
#define DEVICEINFO_H
#include "misc_enum.h"
#include "qptopology_global.h"
#include <QString>
class QPTOPOLOGY_EXPORT QPNodeAttribute
{
public:
    QPNodeAttribute();    
    NODETYPE getType() const;
    void setType(const NODETYPE &value);

    QString getTypeName() const;
    void setTypeName(const QString &value);

    QString getModel() const;
    void setModel(const QString &value);

    QString getSerialN() const;
    void setSerialN(const QString &value);

    QString getInnerN() const;
    void setInnerN(const QString &value);

    QString getDeploy() const;
    void setDeploy(const QString &value);

    NODESTATUS getStatus() const;
    void setStatus(const NODESTATUS &value);

protected:
    NODETYPE type;
    NODESTATUS status;
    QString typeName;
    QString model;
    QString serialN;
    QString innerN;
    QString deploy;

};

#endif // DEVICEINFO_H
