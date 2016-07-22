#ifndef PAUDPSESSIONQUERYMODEL_H
#define PAUDPSESSIONQUERYMODEL_H
#include "qpquerymodel.h"
class PAUDPSessionQueryModel : public QPQueryModel
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit PAUDPSessionQueryModel(QObject *parent = 0);

protected:
    QVariant data(const QModelIndex &item, int role) const;
signals:

public slots:

};

#endif // PAUDPSESSIONQUERYMODEL_H
