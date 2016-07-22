#ifndef PAPKTINFOOPERATION_H
#define PAPKTINFOOPERATION_H

#include "qpocidataoperation.h"

class PAPktInfoOperation : public QPOCIDataOperation
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit PAPktInfoOperation(QObject *parent = 0);

signals:

public slots:
};

#endif // PAPKTINFOOPERATION_H
