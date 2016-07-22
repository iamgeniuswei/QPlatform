#include "qpquerymodel.h"
#include <QModelIndex>
#include <QVariant>

QPQueryModel::QPQueryModel(QObject *parent) :
    QSqlQueryModel(parent)
{

}

void QPQueryModel::setHeaderLabel(const QStringList &headerLabel)
{
    Q_UNUSED(headerLabel);
    int headerSectionCount = (headerLabel.size() <= this->columnCount()) ? headerLabel.size() : this->columnCount();
    for(int i = 0; i< headerSectionCount; i++)
    {
        setHeaderData(i, Qt::Horizontal, headerLabel.value(i));
    }
}

QVariant QPQueryModel::data(const QModelIndex &item, int role) const
{
    QVariant value = QSqlQueryModel::data(item, role);
    return value;
}
