#include "paofflinefilequerymodel.h"

PAOfflineFileQueryModel::PAOfflineFileQueryModel(QObject *parent) :
    QPQueryModel(parent)
{
}


QVariant PAOfflineFileQueryModel::data(const QModelIndex &index, int role) const
{
    QVariant value = QPQueryModel::data(index, role);

    if(value.isValid() && role == Qt::DisplayRole)
    {
        if(index.column() == 4)
            return value.toString().append(" Bytes");

    }
    if(role == Qt::TextAlignmentRole
            && index.column() != 0
            && index.column() != 1
            && index.column() != 2
            && index.column() != 3
            && index.column() != 8)
    {
        value = int(Qt::AlignRight|Qt::AlignVCenter);
    }
    return value;
}
