#ifndef PAIPV4SESSIONQUERYMODEL_H
#define PAIPV4SESSIONQUERYMODEL_H
#include "qpquerymodel.h"
class PAIPV4SessionQueryModel : public QPQueryModel
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit PAIPV4SessionQueryModel(QObject *parent = 0);

protected:
    QVariant data(const QModelIndex &item, int role) const;
signals:

public slots:

};

#endif // PAIPV4SESSIONQUERYMODEL_H
