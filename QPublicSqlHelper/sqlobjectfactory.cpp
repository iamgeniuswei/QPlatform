#include "sqlobjectfactory.h"
#include <QString>
#include "qpdataoperation.h"
QHash<QString, const QMetaObject*> SqlObjectFactory::sqlObjectLib;
QHash<QString, const QMetaObject*> SqlObjectFactory::modelObjectLib;
SqlObjectFactory::SqlObjectFactory()
{
}

SqlObjectFactory::~SqlObjectFactory()
{

}

QObject *SqlObjectFactory::createObject(const QString &objName)
{
    const QMetaObject *metaObj = sqlObjectLib.value(objName);
    if(metaObj)
    {
        QObject *objA = metaObj->newInstance();
        return objA;
    }
    else
        return NULL;
}

QObject *SqlObjectFactory::createModelObject(const QString &objName)
{
    const QMetaObject *meta = modelObjectLib.value(objName);
    if(meta)
    {
        QObject *objB = meta->newInstance();
        return objB;
    }
    else
        return NULL;
}

