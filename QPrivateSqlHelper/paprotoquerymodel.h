#ifndef PAPROTOQUERYMODEL_H
#define PAPROTOQUERYMODEL_H
#include "qpquerymodel.h"
class PAProtoQueryModel : public QPQueryModel
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit PAProtoQueryModel(QObject *parent = 0);
    QVariant data(const QModelIndex &item, int role) const;
signals:

public slots:

};

#endif // PAPROTOQUERYMODEL_H
