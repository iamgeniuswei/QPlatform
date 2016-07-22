#ifndef PAPHYSICALSESSIONQUERYMODEL_H
#define PAPHYSICALSESSIONQUERYMODEL_H
#include "qpquerymodel.h"

class PAPhysicalSessionQueryModel : public QPQueryModel
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit PAPhysicalSessionQueryModel(QObject *parent = 0);
protected:
    QVariant data(const QModelIndex &item, int role) const;

signals:

public slots:

};

#endif // PAPHYSICALSESSIONQUERYMODEL_H
