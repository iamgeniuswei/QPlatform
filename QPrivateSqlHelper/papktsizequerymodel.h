#ifndef PAPKTSIZEQUERYMODEL_H
#define PAPKTSIZEQUERYMODEL_H
#include "qpquerymodel.h"
class PAPktSizeQueryModel : public QPQueryModel
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit PAPktSizeQueryModel(QObject *parent = 0);
protected:
    QVariant data(const QModelIndex &item, int role) const;

signals:

public slots:

};

#endif // PAPKTSIZEQUERYMODEL_H
