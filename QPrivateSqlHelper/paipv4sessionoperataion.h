#ifndef PAIPV4SESSIONOPERATAION_H
#define PAIPV4SESSIONOPERATAION_H

#include "qpocidataoperation.h"

class PAIPV4SessionOperation : public QPOCIDataOperation
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit PAIPV4SessionOperation(QObject *parent = 0);

signals:

public slots:

};

#endif // PAIPV4SESSIONOPERATAION_H
