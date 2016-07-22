#ifndef QOCITASKVIEWOPERATION_H
#define QOCITASKVIEWOPERATION_H

#include <QObject>
#include "qpocidataoperation.h"
#include "qprivatesqlhelper_global.h"
class QPRIVATESQLHELPERSHARED_EXPORT QOCITaskViewOperation : public QPOCIDataOperation
{
    Q_OBJECT
public:
    Q_INVOKABLE QOCITaskViewOperation(QObject *parent = 0);
    Q_INVOKABLE int InsertRecord(DBModel *dataModel);
    Q_INVOKABLE int DeleteRecord(DBModel *dataModel);
    Q_INVOKABLE int UpdateRecord(DBModel *dataModel);
    Q_INVOKABLE DBModel *QueryRecord(int _id);
    Q_INVOKABLE DBModel *QueryByOrigin(int _id);
};

#endif // QOCITASKVIEWOPERATION_H
