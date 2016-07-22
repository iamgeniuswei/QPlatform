#ifndef PAIPV6SESSIONQUERYMODEL_H
#define PAIPV6SESSIONQUERYMODEL_H
#include "qpquerymodel.h"
class PAIPV6SessionQueryModel : public QPQueryModel
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit PAIPV6SessionQueryModel(QObject *parent = 0);

protected:
    QVariant data(const QModelIndex &item, int role) const;
signals:

public slots:

};

#endif // PAIPV6SESSIONQUERYMODEL_H
