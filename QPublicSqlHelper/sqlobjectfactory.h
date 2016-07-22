#ifndef SQLOBJECTFACTORY_H
#define SQLOBJECTFACTORY_H
#include <QHash>
#include <QMetaObject>
#include <QObject>
#include "sqlhelper_global.h"
class QString;
class QPDataOperation;
class SQLHELPEREXPORT SqlObjectFactory
{
public:
    SqlObjectFactory();
    ~SqlObjectFactory();
private:
    static QHash<QString, const QMetaObject*> sqlObjectLib;
    static QHash<QString, const QMetaObject*> modelObjectLib;

public:
    template<typename T>
    void registerObject()
    {
        sqlObjectLib.insert(T::staticMetaObject.className(), &(T::staticMetaObject));
    }

    static QObject *createObject(const QString &objName);

    template<typename T>
    void registerModelObject()
    {
        modelObjectLib.insert(T::staticMetaObject.className(), &(T::staticMetaObject));
    }

    static QObject *createModelObject(const QString &objName);
};

#endif // SQLOBJECTFACTORY_H
