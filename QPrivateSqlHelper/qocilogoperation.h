#ifndef QOCILOGOPERATION_H
#define QOCILOGOPERATION_H
#include "qpocidataoperation.h"
#include "qprivatesqlhelper_global.h"
class QPRIVATESQLHELPERSHARED_EXPORT QOCILogOperation : public QPOCIDataOperation
{
    Q_OBJECT
public:
    Q_INVOKABLE QOCILogOperation(QObject *parent = 0);
    int InsertRecord(DBModel *dataModel, const QString &connName);
    int DeleteRecord(DBModel *dataModel);
    int UpdateRecord(DBModel *dataModel);
    DBModel* QueryRecord(int _id);
};

#endif // QOCILOGOPERATION_H
