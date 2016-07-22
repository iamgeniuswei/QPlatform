#ifndef PARECOVERYFILEOPERATION_H
#define PARECOVERYFILEOPERATION_H

#include "qpocidataoperation.h"

class PARecoveryFileOperation : public QPOCIDataOperation
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit PARecoveryFileOperation(QObject *parent = 0);

signals:

public slots:

};

#endif // PARECOVERYFILEOPERATION_H
