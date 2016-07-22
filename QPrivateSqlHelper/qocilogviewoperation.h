#ifndef QOCILOGVIEWOPERATION_H
#define QOCILOGVIEWOPERATION_H
#include "qpocidataoperation.h"
#include "qprivatesqlhelper_global.h"

class QPRIVATESQLHELPERSHARED_EXPORT QOCILogViewOperation : public QPOCIDataOperation
{
    Q_OBJECT
public:
    Q_INVOKABLE QOCILogViewOperation(QObject *parent =0);
    DBModel *QueryRecord(int _id);
};

#endif // QOCILOGVIEWOPERATION_H
