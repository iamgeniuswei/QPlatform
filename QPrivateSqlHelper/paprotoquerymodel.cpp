#include "paprotoquerymodel.h"
#include <QVariant>
PAProtoQueryModel::PAProtoQueryModel(QObject *parent) :
    QPQueryModel(parent)
{
}

QVariant PAProtoQueryModel::data(const QModelIndex &item, int role) const
{
    QVariant value = QPQueryModel::data(item, role);
    if(role == Qt::TextAlignmentRole)
    {
        value = int(Qt::AlignRight|Qt::AlignVCenter);
    }
    return value;
}
