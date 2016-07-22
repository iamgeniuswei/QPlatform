#ifndef PAFLOWQUERYMODEL_H
#define PAFLOWQUERYMODEL_H
#include "qpquerymodel.h"
class PAFlowQueryModel : public QPQueryModel
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit PAFlowQueryModel(QObject *parent = 0);
protected:
    QVariant data(const QModelIndex &item, int role) const;

signals:

public slots:

};

#endif // PAFLOWQUERYMODEL_H
