#ifndef QOCIRESULTOPERATION_H
#define QOCIRESULTOPERATION_H
#include "qpocidataoperation.h"
#include "qprivatesqlhelper_global.h"
class QPRIVATESQLHELPERSHARED_EXPORT QOCIResultOperation : public QPOCIDataOperation
{
    Q_OBJECT
public:
    Q_INVOKABLE QOCIResultOperation(QObject *parent = 0);
    int InsertRecord(DBModel *dataModel, const QString &connName = QString());
    int DeleteRecord(DBModel *dataModel, const QString &connName = QString());
    int UpdateRecord(DBModel *dataModel, const QString &connName = QString());
    DBModel* QueryRecord(int _id);
    DBModel* QueryRecord(const int _id, const QString &connName);
};

#endif // QOCIRESULTOPERATION_H
