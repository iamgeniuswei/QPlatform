#ifndef PATCPSESSIONOPERATION_H
#define PATCPSESSIONOPERATION_H

#include "qpocidataoperation.h"

class PATCPSessionOperation : public QPOCIDataOperation
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit PATCPSessionOperation(QObject *parent =0);

signals:

public slots:

};

#endif // PATCPSESSIONOPERATION_H
