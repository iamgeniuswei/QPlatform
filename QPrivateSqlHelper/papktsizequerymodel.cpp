#include "papktsizequerymodel.h"

PAPktSizeQueryModel::PAPktSizeQueryModel(QObject *parent) :
    QPQueryModel(parent)
{
}

QVariant PAPktSizeQueryModel::data(const QModelIndex &index, int role) const
{
    QVariant value = QPQueryModel::data(index, role);
    if(value.isValid() && role == Qt::DisplayRole)
    {
        if(index.column() == 0 && 0 != index.row() )
            return value.toString().append(" Bytes");
        if(index.column() == 1)
            return value.toString().append(" Bytes");
        if(index.column() == 3)
            return value.toString().append(" %");
        if(index.column() == 4)
            return value.toString().append(" Bps");
        if(index.column() == 5)
            return value.toString().append(" pps");
    }
    if(role == Qt::TextAlignmentRole && index.column() != 0)
    {
        value = int(Qt::AlignRight|Qt::AlignVCenter);
    }

    return value;
}
