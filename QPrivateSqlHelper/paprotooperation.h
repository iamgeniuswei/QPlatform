#ifndef PAPROTOOPERATION_H
#define PAPROTOOPERATION_H

#include "qpocidataoperation.h"

class PAProtoOperation : public QPOCIDataOperation
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit PAProtoOperation(QObject *parent =0);

signals:

public slots:

};

#endif // PAPROTOOPERATION_H
