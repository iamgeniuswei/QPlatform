#ifndef PAOFFLINEFILEOPERATION_H
#define PAOFFLINEFILEOPERATION_H

#include "qpocidataoperation.h"

class PAOfflineFileOperation : public QPOCIDataOperation
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit PAOfflineFileOperation(QObject *parent = 0);
    DBModel* QueryRecord(const int _id, const QString &connName);

signals:

public slots:

};

#endif // PAOFFLINEFILEOPERATION_H
