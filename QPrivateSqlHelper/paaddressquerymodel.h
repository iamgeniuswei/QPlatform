#ifndef PAADDRESSQUERYMODEL_H
#define PAADDRESSQUERYMODEL_H
#include "qpquerymodel.h"
class PAAddressQueryModel : public QPQueryModel
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit PAAddressQueryModel(QObject *parent = 0);
    QVariant data(const QModelIndex &item, int role) const;
signals:

public slots:

};

#endif // PAADDRESSQUERYMODEL_H
