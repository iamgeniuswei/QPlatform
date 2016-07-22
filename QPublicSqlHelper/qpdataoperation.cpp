#include "qpdataoperation.h"
#include "private/qpdataoperation_p.h"
QPDataOperation::QPDataOperation(QObject *parent):
    QObject(parent),
    d_ptr(new QPDataOperationPrivate(this))
{

}

QString QPDataOperation::tableName() const
{
    Q_D(const QPDataOperation);
    return d->_tableName;
}

void QPDataOperation::setTableName(const QString &tableName)
{
    Q_D(QPDataOperation);
    d->_tableName = tableName;
}
