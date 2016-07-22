#ifndef QUERYMODEL_H
#define QUERYMODEL_H
#include <QSqlQueryModel>
#include "sqlhelper_global.h"

class SQLHELPEREXPORT QPQueryModel : public QSqlQueryModel
{
    Q_OBJECT
public:
    explicit QPQueryModel(QObject *parent = 0);
    virtual void setHeaderLabel(const QStringList &headerLabel);
protected:
    virtual QVariant data(const QModelIndex &item, int role) const;
};

#endif // QUERYMODEL_H
