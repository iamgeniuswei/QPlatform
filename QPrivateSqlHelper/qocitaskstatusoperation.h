#ifndef QOCITASKSTATUSOPERATION_H
#define QOCITASKSTATUSOPERATION_H

#include "qpocidataoperation.h"

class QOCITaskStatusOperation : public QPOCIDataOperation
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit QOCITaskStatusOperation(QObject *parent = 0);
    int InsertRecord(DBModel *dataModel, const QString &connName = QString());
    int UpdateRecord(DBModel *dataModel, const QString &connName);

signals:

public slots:

};

#endif // QOCITASKSTATUSOPERATION_H
