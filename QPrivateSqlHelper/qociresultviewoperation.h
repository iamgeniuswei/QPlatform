#ifndef QOCIRESULTVIEWOPERATION_H
#define QOCIRESULTVIEWOPERATION_H

#include <QObject>
#include "qpocidataoperation.h"
#include "qprivatesqlhelper_global.h"

class QPRIVATESQLHELPERSHARED_EXPORT QOCIResultViewOperation : public QPOCIDataOperation
{
    Q_OBJECT
public:
    Q_INVOKABLE QOCIResultViewOperation(QObject *parent = 0);
    Q_INVOKABLE int InsertRecord(DBModel *dataModel);
    Q_INVOKABLE int DeleteRecord(DBModel *dataModel);
    Q_INVOKABLE int UpdateRecord(DBModel *dataModel);
    Q_INVOKABLE DBModel *QueryRecord(const int _id, const QString &connName);

};

#endif // QOCIRESULTVIEWOPERATION_H
