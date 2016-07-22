#ifndef PAUDPSESSIONOPERATION_H
#define PAUDPSESSIONOPERATION_H

#include "qpocidataoperation.h"

class PAUDPSessionOperation : public QPOCIDataOperation
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit PAUDPSessionOperation(QObject *parent = 0);

signals:

public slots:

};

#endif // PAUDPSESSIONOPERATION_H
