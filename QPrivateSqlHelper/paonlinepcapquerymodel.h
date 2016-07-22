#ifndef PAONLINEPCAPQUERYMODEL_H
#define PAONLINEPCAPQUERYMODEL_H
#include "qpquerymodel.h"

class PAOnlinePcapQueryModel : public QPQueryModel
{
    Q_OBJECT
public:
    explicit PAOnlinePcapQueryModel(QObject *parent = 0);

protected:
    QVariant data(const QModelIndex &item, int role) const;

signals:

public slots:

};

#endif // PAONLINEPCAPQUERYMODEL_H
