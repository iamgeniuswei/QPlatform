#ifndef QOCITASKOPERATION_H
#define QOCITASKOPERATION_H
#include "qpocidataoperation.h"
#include "qprivatesqlhelper_global.h"
class QPRIVATESQLHELPERSHARED_EXPORT QOCITaskOperation : public QPOCIDataOperation
{
    Q_OBJECT
public:
    Q_INVOKABLE QOCITaskOperation(QObject *parent =0);
//    Q_INVOKABLE virtual bool QueryPage(QSqlQueryModel *model, int index, int step, const QString &condition);
//    Q_INVOKABLE virtual int QueryCount(const QString &condition);
//    Q_INVOKABLE int InsertRecord(DBModel *dataModel);
    int InsertRecord(DBModel *dataModel, const QString &connName = QString());
    int DeleteRecord(DBModel *dataModel);
    int UpdateRecord(DBModel *dataModel, const QString &connName = QString());
    DBModel* QueryRecord(int _id);
    DBModel* QueryRecord(const int _id, const QString &connName);
    DBModel* QueryRecord(const QString& condition, const QString& connName);

    DBModel *QueryByOrigin(int _id);

private:
//    QString _tableName;
};

#endif // QOCITASKOPERATION_H
