#include "paonlinepcapquerymodel.h"

PAOnlinePcapQueryModel::PAOnlinePcapQueryModel(QObject *parent) :
    QPQueryModel(parent)
{
}
QVariant PAOnlinePcapQueryModel::data(const QModelIndex &index, int role) const
{
    QVariant value = QPQueryModel::data(index, role);

    if(value.isValid() && role == Qt::DisplayRole)
    {
        if(index.column() == 4)
            return value.toString().append(" Bytes");

    }
    if(role == Qt::TextAlignmentRole
            && (index.column() == 7
                || index.column() == 8
                || index.column() == 9)
            )
    {
        value = int(Qt::AlignRight|Qt::AlignVCenter);
    }
    if(role == Qt::TextAlignmentRole && index.column() == 4)
    {
        value = int(Qt::AlignRight|Qt::AlignVCenter);
    }
    return value;
}
