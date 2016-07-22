#include "pataskinfoquerymodel.h"
#include <QDateTime>
#include <QDebug>
PATaskInfoQueryModel::PATaskInfoQueryModel(QObject *parent) :
    QPQueryModel(parent)
{
}

QVariant PATaskInfoQueryModel::data(const QModelIndex &index, int role) const
{
    QVariant value = QPQueryModel::data(index, role);

    if(value.isValid() && role == Qt::DisplayRole && index.column() == 2)
    {

    }


    if(role == Qt::TextAlignmentRole && index.column() != 0 && index.column() != 1)
    {
        value = int(Qt::AlignCenter|Qt::AlignVCenter);
    }
    return value;
}
