#ifndef QOCIUSEROPERATION_H
#define QOCIUSEROPERATION_H

#include "qpocidataoperation.h"

class QOCIUserOperation : public QPOCIDataOperation
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit QOCIUserOperation(QObject *parent = 0);
    virtual DBModel*QueryRecord(const QString& condition);
    virtual DBModel *QueryRecord(const QString &condition, const QString &connName);
signals:

public slots:

};

#endif // QOCIUSEROPERATION_H
