#ifndef SQLWORKTHREAD_H
#define SQLWORKTHREAD_H
#include <QThread>
#include <QStringList>
#include "sqlhelper_global.h"
class DBModel;
class QPQueryModel;

///
/// \brief The SqlWorkThread class.\n
/// SqlWorkThread provide multi-thread database operation.\n
/// With this class, we can migrate database operation into workthread, \n
/// and GUI Thread will not be blocked.\n
/// You'd best instantiatilize the sub-class of this class.\n
/// Example \n
/// \code
/// SqlWorkThread *thread = new QueryThread;
/// thread->setQueryPageParameter(model,\
///                                 tableName,
///                                 index,\
///                                 step,\
///                                 condition);
/// connect(thread, SIGNAL(finished), thread, SLOT(deleteLater));
/// thread->start()
/// \endcode
class SQLHELPEREXPORT QPSqlWorkThread : public QThread
{
    Q_OBJECT
    Q_ENUMS(SQLWORKMODE)
    Q_PROPERTY(SQLWORKMODE sqlWorkMode READ sqlWorkMode WRITE setSqlWorkMode)
public:
    ///
    /// \brief The SQLWORKMODE enum.\n
    /// Enum the SQL work-thread mode.
    enum SQLWORKMODE{
        QUERYPAGE,
        QUERYCOUNT,
        QUERYROW,
        QUERYROWBYCONDITION,
        QUERYLIST,
        INSERT,
        DELETE,
        UPDATE
    };
    explicit QPSqlWorkThread(QObject *parent = 0);
    ~QPSqlWorkThread();
    ///
    /// \brief setQueryPageParameterWithConnection
    /// Set the parameters of QueryPage with new database connection.
    /// \param index : int. the index of the page.
    /// \param step : int. the step of the page.
    /// \param tableName: QString. the tablename to query.
    /// \param condition : QString. query conidtion if has.
    /// \param connName : QString. the database connection name, not default connection.
    ///
    virtual void setQueryPageParameter(unsigned int index = 0,\
                                       unsigned int step = 100,\
                                       const QString &tableName = QString(),\
                                       const QString &condition = QString(),\
                                       const QString &realTable = QString(),\
                                       const QString &connName = QString());

//    ///
//    /// \brief setQueryPageParameterWithConnection
//    /// override function. Set the parameters of QueryPage with new database connection.
//    /// \param index : int. the index of the page.
//    /// \param step : int. the step of the page.
//    /// \param tableName : QString. the tablename to query.
//    /// \param connName : QString. the database connection name, not default connection.
//    ///
//    virtual void setQueryPageParameterWithConnection(unsigned int index = 0,\
//                                       unsigned int step = 100,\
//                                       const QString &tableName = QString(),\
//                                       const QString &connName = QString());

//    ///
//    /// \brief setQueryPageParameter
//    /// Set the parameters of QueryPage using default database connection.
//    /// \param index : int. the index of the page.
//    /// \param step : int. the step of the page.
//    /// \param tableName : QString. the tablename to query.
//    ///
//    virtual void setQueryPageParameter(unsigned int index = 0,\
//                                       unsigned int step = 100,\
//                                       const QString &tableName = QString());

//    ///
//    /// \brief setQueryPageParameter
//    /// override function. Set the parameters of QueryPage using default database connection.
//    /// \param index : int. the index of the page.
//    /// \param step : int. the step of the page.
//    /// \param tableName : QString. the tablename to query.
//    /// \param condition : QString. query condition if has.
//    ///
//    virtual void setQueryPageParameter(unsigned int index = 0,\
//                                       unsigned int step = 100,\
//                                       const QString &tableName = QString(),\
//                                       const QString &condition = QString());

//    ///
//    /// \brief setQueryCountParameterWithConnection
//    /// set query count of the data using new database connection.
//    /// \param tableName : QString. table to query.
//    /// \param condition : QString. query condition if has.
//    /// \param connName : QString. the database connection name, not default connection.
//    ///
//    virtual void setQueryCountParameterWithConnection(const QString &tableName = QString(),\
//                                const QString &condition = QString(),\
//                                const QString &connName = QString());
//    ///
//    /// \brief setQueryCountParameterWithConnection
//    /// override function. set query count of the data using new database connection.
//    /// \param tableName : QString. table to query.
//    /// \param connName : QString. the database connection name, not default connection.
//    ///
//    virtual void setQueryCountParameterWithConnection(const QString &tableName = QString(),\
//                                const QString &connName = QString());
//    ///
//    /// \brief setQueryCountParameter
//    /// set query count of the data using default database connection.
//    /// \param tableName : QString. table to query.
//    ///
//    virtual void setQueryCountParameter(const QString &tableName = QString());
    ///
    /// \brief setQueryCountParameter
    /// override function. set query count of the data using default database connection.
    /// \param tableName : QString. table to query.
    /// \param condition : QString. query condition if has.
    ///
    virtual void setQueryCountParameter(const QString &tableName = QString(),\
                                        const QString &condition = QString(),\
                                        const QString &realTable = QString(),\
                                        const QString &connName = QString());


    virtual void setQueryRowParameter(const unsigned int _id, const QString &tableName = QString(), const QString &connName = QString());
    virtual void setQueryRowParameter(const QString& conditon, const QString &tableName = QString(), const QString &connName = QString());
    virtual void setNonQueryParameter(const QString &tableName,\
                                      DBModel *const model);
    virtual void setNonQueryParameter(const QString &tableName, const QString &connName, DBModel * const model);

    ///
    /// \brief sqlWorkMode
    /// get the PROPERTY sqlworkmode.
    /// \return SQLWORKMODE enum
    ///
    SQLWORKMODE sqlWorkMode() const;
    ///
    /// \brief setSqlWorkMode
    /// set the PROPERTY sqlworkmode.
    /// \param mode
    ///
    void setSqlWorkMode(SQLWORKMODE mode);

signals:
    ///
    /// \brief sendQueryPageResult
    /// sent the query page result.
    /// \param model : QueryModel. The result of the query page.
    ///
    void sendQueryPageResult(QPQueryModel *model);
    ///
    /// \brief sendQueryCountResult
    /// set the query count result.
    /// \param count : int. The result of the query count.
    ///
    void sendQueryCountResult(int count);
    void sendQueryRowResult(DBModel *dbModel);
    void sendNonQueryResult(int count);
    void sendQueryListResult(QStringList list);
    ///
    /// \brief sendErrorMsg
    /// set the error msg if error occured.
    ///
    void sendErrorMsg();

private:
    volatile SQLWORKMODE _workmode;
};

#endif // SQLWORKTHREAD_H
