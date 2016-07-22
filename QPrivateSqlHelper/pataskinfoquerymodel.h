#ifndef PATASKINFOQUERYMODEL_H
#define PATASKINFOQUERYMODEL_H
#include "qpquerymodel.h"
class PATaskInfoQueryModel : public QPQueryModel
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit PATaskInfoQueryModel(QObject *parent = 0);

protected:
    QVariant data(const QModelIndex &item, int role) const;

signals:

public slots:

};

#endif // PATASKINFOQUERYMODEL_H
