#ifndef PAADDRESSOPERATION_H
#define PAADDRESSOPERATION_H

#include "qpocidataoperation.h"

class PAAddressOperation : public QPOCIDataOperation
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit PAAddressOperation(QObject *parent = 0);

signals:

public slots:

};

#endif // PAADDRESSOPERATION_H
