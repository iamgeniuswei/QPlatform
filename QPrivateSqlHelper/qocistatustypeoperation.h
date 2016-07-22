#ifndef QOCISTAUSTYPEOPERATION_H
#define QOCISTAUSTYPEOPERATION_H

#include "qpocidataoperation.h"

class QOCIStatusTypeOperation : public QPOCIDataOperation
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit QOCIStatusTypeOperation(QObject *parent = 0);
    QStringList QueryRecordList(const QString &condition, const QString &connName);

signals:

public slots:

};

#endif // QOCISTAUSTYPEOPERATION_H
