#ifndef QOCISOFTWARESTATUS_H
#define QOCISOFTWARESTATUS_H

#include "qpocidataoperation.h"
class QOCISoftwareStatusOperation : public QPOCIDataOperation
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit QOCISoftwareStatusOperation(QObject *parent = 0);
    int UpdateRecord(DBModel *dataModel, const QString &connName);

signals:

public slots:

};

#endif // QOCISOFTWARESTATUS_H
