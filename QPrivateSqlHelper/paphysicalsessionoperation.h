#ifndef PAPHYSICALSESSIONOPERATION_H
#define PAPHYSICALSESSIONOPERATION_H

#include "qpocidataoperation.h"

class PAPhysicalSessionOperation : public QPOCIDataOperation
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit PAPhysicalSessionOperation(QObject *parent = 0);

signals:

public slots:

};

#endif // PAPHYSICALSESSIONOPERATION_H
