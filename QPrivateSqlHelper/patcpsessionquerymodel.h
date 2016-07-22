#ifndef PATCPSESSIONQUERYMODEL_H
#define PATCPSESSIONQUERYMODEL_H
#include "qpquerymodel.h"
class PATCPSessionQueryModel : public QPQueryModel
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit PATCPSessionQueryModel(QObject *parent = 0);

protected:
    QVariant data(const QModelIndex &item, int role) const;
signals:

public slots:

};

#endif // PATCPSESSIONQUERYMODEL_H
