#ifndef PAONLINEFILEOPERATION_H
#define PAONLINEFILEOPERATION_H

#include "qpocidataoperation.h"

class PAOnlineFileOperation : public QPOCIDataOperation
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit PAOnlineFileOperation(QObject *parent = 0);
    DBModel *QueryRecord(const int _id, const QString &connName);
signals:

public slots:

};

#endif // PAONLINEFILEOPERATION_H
