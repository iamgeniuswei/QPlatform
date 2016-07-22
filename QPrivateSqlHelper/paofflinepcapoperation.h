#ifndef PAOFFLINEPCAPOPERATION_H
#define PAOFFLINEPCAPOPERATION_H

#include "qpocidataoperation.h"

class PAOfflinePcapOperation : public QPOCIDataOperation
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit PAOfflinePcapOperation(QObject *parent = 0);

signals:

public slots:

};

#endif // PAOFFLINEPCAPOPERATION_H
