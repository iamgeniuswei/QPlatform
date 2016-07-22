#ifndef QOCIUSERSTATUSOPERATION_H
#define QOCIUSERSTATUSOPERATION_H

#include "qpocidataoperation.h"

class QOCIUserStatusOperation : public QPOCIDataOperation
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit QOCIUserStatusOperation(QObject *parent = 0);
    int UpdateRecord(DBModel *dataModel, const QString &connName);

signals:

public slots:

};

#endif // QOCIUSERSTATUSOPERATION_H
