#ifndef QPOCIDATAOPERATION_H
#define QPOCIDATAOPERATION_H
#include "qpdataoperation.h"
#include "sqlhelper_global.h"
class QSqlQuery;
class QPQueryModel;

///
/// \brief The QPOCIDataOperation class
/// QPOCIDataOperation provide the interface to manipute the oracle database DataTable.\n
/// \attention
/// Differencet to SqlCommand. SqlCommand is a common opertaion to all Data Tables.\n
/// Sub-class of QPOCIDataOperation is the special Operation to the oracle assigned Table.\n
/// the sub-class of IDataOpertaion must be Q_INVOKABLE.
/// \author Geniuswei
/// \date 2015-06-11
///
class SQLHELPEREXPORT QPOCIDataOperation : public QPDataOperation
{
    Q_OBJECT
public:
    explicit QPOCIDataOperation(QObject *parent);
    virtual bool QueryPage(QPQueryModel *model, const int index, const int step, const QString &condition = QString(), const QString &connName = QString());
//    virtual bool QueryPage(QueryModel *model, int index, int step, const QString &condition);
    virtual int QueryCount(const QString &condition, const QString &connName);
//    virtual int QueryCount(const QString &condition);
//    virtual int InsertRecord(DBModel *dataModel);
    virtual int InsertRecord(DBModel *dataModel, const QString &connName = QString());
    virtual int DeleteRecord(DBModel *dataModel, const QString &connName = QString());
    virtual int UpdateRecord(DBModel *dataModel, const QString &connName = QString());
//    virtual DBModel *QueryRecord(int _id);
    virtual DBModel* QueryRecord(const int _id, const QString &connName);
//    virtual DBModel*QueryRecord(const QString& condition);
    virtual DBModel *QueryRecord(const QString &condition, const QString &connName);
    virtual QStringList QueryRecordList(const QString &condition, const QString &connName);

    int ExecuteQSqlQuery(QSqlQuery &query);
    int ExecuteSql(const QString &sql, const QString &connName);
};

#endif // QPOCIDATAOPERATION_H
