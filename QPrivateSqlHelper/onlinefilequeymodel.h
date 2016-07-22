#ifndef ONLINEFILEQUEYMODEL_H
#define ONLINEFILEQUEYMODEL_H

#include "qpquerymodel.h"
#include "sqlhelper_global.h"

class SQLHELPEREXPORT QMySqlFileQueryModel : public QPQueryModel
{
    Q_OBJECT
public:
    Q_INVOKABLE  QMySqlFileQueryModel(QObject *parent = 0);
protected:
    QVariant data(const QModelIndex &item, int role) const;

signals:

public slots:

};

#endif // ONLINEFILEQUEYMODEL_H
