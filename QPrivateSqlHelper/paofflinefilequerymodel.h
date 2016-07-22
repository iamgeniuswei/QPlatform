#ifndef PAOFFLINEFILEQUERYMODEL_H
#define PAOFFLINEFILEQUERYMODEL_H

#include "qpquerymodel.h"

class PAOfflineFileQueryModel : public QPQueryModel
{
    Q_OBJECT
public:
    explicit PAOfflineFileQueryModel(QObject *parent = 0);

protected:
    QVariant data(const QModelIndex &item, int role) const;

signals:

public slots:

};



#endif // PAOFFLINEFILEQUERYMODEL_H
