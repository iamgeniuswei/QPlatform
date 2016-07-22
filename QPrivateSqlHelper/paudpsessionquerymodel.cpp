#include "paudpsessionquerymodel.h"
#include <QIcon>
PAUDPSessionQueryModel::PAUDPSessionQueryModel(QObject *parent) :
    QPQueryModel(parent)
{
}

QVariant PAUDPSessionQueryModel::data(const QModelIndex &index, int role) const
{
    QVariant value = QPQueryModel::data(index, role);
    if(role == Qt::DecorationRole)
    {
        if(index.column() == 1)
            return QVariant::fromValue(QIcon(":/TCPIP/SIP"));
        if(index.column() == 2)
            return QVariant::fromValue(QIcon(":/TCPIP/DIP"));
    }
    if(value.isValid() && role == Qt::DisplayRole)
    {
        if(index.column() == 6)
            return value.toString().append(" s");
        if(index.column() == 7)
            return value.toString().append(" Bytes");
        if(index.column() == 9)
            return value.toString().append(" Bytes");
        if(index.column() == 11)
            return value.toString().append(" Bytes");
    }

    if(role == Qt::TextAlignmentRole && index.column() != 0 && index.column() != 1 && index.column() != 2)
    {
        value = int(Qt::AlignRight|Qt::AlignVCenter);
    }
    return value;
}
