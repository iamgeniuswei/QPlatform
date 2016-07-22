#include "paaddressquerymodel.h"
#include <QVariant>
PAAddressQueryModel::PAAddressQueryModel(QObject *parent) :
    QPQueryModel(parent)
{
}

QVariant PAAddressQueryModel::data(const QModelIndex &item, int role) const
{
    QVariant value = QPQueryModel::data(item, role);
    if(role == Qt::TextAlignmentRole)
    {
        value = int(Qt::AlignRight|Qt::AlignVCenter);
    }
    return value;
}
