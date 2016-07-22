#ifndef QpDATAOPERATION_H
#define QpDATAOPERATION_H
#include <QObject>
#include "sqlhelper_global.h"
class DBModel;
class QPQueryModel;
class QPDataOperationPrivate;
///
/// \brief The QPDataOperation class
/// QPDataOperation provide the interface to manipute the concrete DataTable.\n
/// \attention
/// Differencet to SqlCommand. SqlCommand is a common opertaion to all Data Tables.\n
/// Sub-class of QpDataOperation is the special Operation to the assigned Table.\n
/// We can use QpDataOperation by map<class-Name, class-Instance>.
/// \code
/// QPDataOperation *operation = qobject_cast<QPDataOperation*>(SqlObjectFactory::createObject(_tableOperation));
/// \endcode
/// _tableOperation is the sub-class-name of the QPDataOperation.\n
/// the sub-class of QPOCIDataOpertaion must be Q_INVOKABLE.
/// \author Geniuswei
/// \date 2015-06-11
///
class SQLHELPEREXPORT QPDataOperation : public QObject
{
    Q_OBJECT    
    Q_PROPERTY(QString tableName READ tableName WRITE setTableName)
public:
    explicit QPDataOperation(QObject *parent = 0);
    ///
    /// \brief Execute query data model by page in table with assigend conditon\n
    /// then assign the data model to QSqlQueryModel.\n
    /// if success, return true \n
    /// if fail, return false. you can get the error infomation by:\n
    /// \code
    /// ErrorInfo info;
    /// ErrorInfoQueue queue;
    /// queue.getLastError(&info)
    /// qDebug() << info.errorNo() << info.errorMsg();
    /// \endcode
    /// \param model : QueryModel, Given by user and return to user.
    /// \param index : int. the start position in table.
    /// \param step : int. the rows to query.
    /// \param conditon : QString. the query condition.
    /// \param connName : QString. the database name.
    /// \return true/false
    /// \attention This function is virtual funtion. must be reinplemented by sub-class.
    /// \author Geniuswei
    /// \date 2015-06-12
    /// \data 2015-11-02
    /// \brief add connName as a parameter.
    virtual bool QueryPage(QPQueryModel *model, const int index, const int step, const QString &condition = QString(), const QString &connName = QString()) = 0;
//    virtual bool QueryPage(QueryModel *model, int index, int step, const QString &condition) = 0;
    ///
    /// \brief Execute query data row count in table with assigned condition.\n
    /// if success, return the row count in table(>=0). \n
    /// if fail, return -1. you can get the error infomation by:\n
    /// \code
    /// ErrorInfo info;
    /// ErrorInfoQueue queue;
    /// queue.getLastError(&info)
    /// qDebug() << info.errorNo() << info.errorMsg();
    /// \endcode
    /// \param condition : QString. The query condition.
    /// \param connName : QString. the database name.
    /// \return row count : int.
    /// \author Geniuswei
    /// \date 2015-06-12 Created.
    /// \date 2015-11-02
    /// \brief add connName as a parmeter.
    /// \attention This function is virtual funtion. must be reinplemented by sub-class.
    virtual int QueryCount(const QString &condition, const QString &connName = QString()) = 0;
//    virtual int QueryCount(const QString &condition) = 0;

    ///
    /// \brief Execute insert a record into table.\n
    /// if success, return the row count that has been inserted.\n
    /// if fail, return -1. you can get the error infomation by:\n
    /// \code
    /// ErrorInfo info;
    /// ErrorInfoQueue queue;
    /// queue.getLastError(&info)
    /// qDebug() << info.errorNo() << info.errorMsg();
    /// \endcode
    /// \param dataModel : DBModel. The object which need to be inserted.
    /// \param connName : QString. the database name.
    /// \return row count inserted : int
    /// \author Geniuswei
    /// \date 2015-06-15
    /// \date 2015-11-01
    /// \brief add connName as a parameter.
    /// \attention This function is virtual funtion. must be reinplemented by sub-class.
    virtual int InsertRecord(DBModel *dataModel, const QString &connName = QString()) = 0;

    ///
    /// \brief Execute delete a record in table.\n
    /// if success, return the row count that has been deleted.\n
    /// if fail, return -1. you can get the error infomation by: \n
    /// \code
    /// ErrorInfo info;
    /// ErrorInfoQueue queue;
    /// queue.getLastError(&info)
    /// qDebug() << info.errorNo() << info.errorMsg();
    /// \endcode
    /// \param dataModel : DBModel. the record to delete.
    /// \param connName : QString. the database name.
    /// \return row count deleted : int
    /// \attention This function is virtual funtion. must be reinplemented by sub-class.
    /// \date 2015-11-01
    virtual int DeleteRecord(DBModel *dataModel, const QString &connName = QString()) = 0;

    ///
    /// \brief Execute update a record in table.\n
    /// if success, return the row count that has been update.\n
    /// if fail, return -1. you can get the error infomation by: \n
    /// \code
    /// ErrorInfo info;
    /// ErrorInfoQueue queue;
    /// queue.getLastError(&info)
    /// qDebug() << info.errorNo() << info.errorMsg();
    /// \endcode
    /// \param dataModel : DBModel. the record to update.
    /// \param connName : QString. the database name.
    /// \return row count update : int
    /// \attention This function is virtual funtion. must be reinplemented by sub-class.
    /// \date 2015-11-01
    virtual int UpdateRecord(DBModel *dataModel, const QString &connName = QString()) = 0;


    ///
    /// \brief Execute query  a data model by id in table.\n
    /// then assign the data model to DBModel.\n
    /// if success, return DBModel* \n
    /// if fail, return NULL. you can get the error infomation by:\n
    /// \code
    /// ErrorInfo info;
    /// ErrorInfoQueue queue;
    /// queue.getLastError(&info)
    /// qDebug() << info.errorNo() << info.errorMsg();
    /// \endcode
    /// \param _id : int the id of record in table.
    /// \param connName : QString. the database name.
    /// \return DBModel : the abstract model of record.
    /// \attention This function is virtual funtion. must be reinplemented by sub-class.
    /// \author Geniuswei
    /// \date 2015-06-12
    /// \data 2015-11-02
    /// \brief add connName as a parameter.
//    virtual DBModel* QueryRecord(int _id) = 0;
    virtual DBModel* QueryRecord(const int _id, const QString &connName) = 0;

    ///
    /// \brief Execute query  a data model by condition in table.\n
    /// then assign the data model to DBModel.\n
    /// if success, return DBModel* \n
    /// if fail, return NULL. you can get the error infomation by:\n
    /// \code
    /// ErrorInfo info;
    /// ErrorInfoQueue queue;
    /// queue.getLastError(&info)
    /// qDebug() << info.errorNo() << info.errorMsg();
    /// \endcode
    /// \param conditon : QString. the query condition.
    /// \param connName : QString. the database name.
    /// \return DBModel : the abstract model of record.
    /// \attention This function is virtual funtion. must be reinplemented by sub-class.
    /// \author Geniuswei
    /// \date 2015-06-12
    /// \data 2015-11-02
//    virtual DBModel*QueryRecord(const QString& condition) = 0;
    virtual DBModel *QueryRecord(const QString &condition, const QString &connName) = 0;
    virtual QStringList QueryRecordList(const QString &condition, const QString &connName) = 0;

    QString tableName() const;
    void setTableName(const QString &tableName);

private:
    QPDataOperationPrivate *const d_ptr;
    Q_DECLARE_PRIVATE(QPDataOperation)
};

#endif // QpDATAOPERATION_H
