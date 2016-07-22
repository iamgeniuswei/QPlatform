#ifndef PAIPV6SESSIONOPERATION_H
#define PAIPV6SESSIONOPERATION_H

#include "qpocidataoperation.h"

class PAIPV6SessionOperation : public QPOCIDataOperation
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit PAIPV6SessionOperation(QObject *parent = 0);

signals:

public slots:

};

#endif // PAIPV6SESSIONOPERATION_H
