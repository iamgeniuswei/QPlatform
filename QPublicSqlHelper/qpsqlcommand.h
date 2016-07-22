#ifndef SQLCOMMAND_H
#define SQLCOMMAND_H
#include <QString>
class QSqlQuery;
class QPQueryModel;
///
/// \brief The QPSqlCommand class \n
/// QPSqlCommand provide the basic database operation, such as \n
/// insert\n
/// delete\n
/// update\n
/// query\n etc.
/// in QT C++ code. you can use it by:\n
/// \code
/// QPSqlCommand *command = new QPSqlCommand;
/// if(command->execNoQuerySQL(sql) != -1)
/// {
///     success;
///     delete command;
///     command = NULL;
/// }
/// else
/// {
///     fail;
///     delete command;
///     command = NULL;
/// }
/// \endcode
/// \attention
/// Because there are some difference in variety database system.\n
/// So some operations must be reinplemented in sub-class to support the special \n
/// operation in concrete database system. such as queryPage in Oracle\n
/// and MySQL, so in your code, it's best to use sub-class, don't instantialize this class.

class QPSqlCommand
{
public:
    QPSqlCommand();
    ///
    /// \brief Execute insert/update/delete etc non-query sql\n
    /// if \bold success, return the affected rows(>=0),\n
    /// if \bold fail, return -1, you can get the error infomation by:
    /// \code
    /// ErrorInfo info;
    /// ErrorInfoQueue queue;
    /// queue.getLastError(&info)
    /// qDebug() << info.errorNo() << info.errorMsg();
    /// \endcode
    /// \param sql : QString. the sql to execute.
    /// \param connName : QString. the database name.
    /// \return the affacted rows :int
    /// \author Geniuswei
    /// \date 2015-06-12
    int execNoQuerySQL(const QString &sql, const QString &connName);

    ///
    /// \brief Sometimes, we have to execute QSqlQuery directly.\n
    /// if \bold success, return the affected rows(>=0),\n
    /// if \bold fail, return -1, you can get the error infomation by:
    /// \code
    /// ErrorInfo info;
    /// ErrorInfoQueue queue;
    /// queue.getLastError(&info)
    /// qDebug() << info.errorNo() << info.errorMsg();
    /// \endcode
    /// \param query : QSqlQuery.
    /// \return the affacted rows :int
    /// \author Geniuswei
    /// \date 2015-06-12
    int execQSqlQuery(QSqlQuery &query);

    ///
    /// \brief Execute query data model according sql, assign the data model to QSqlQueryModel\n
    /// if success, return true\n
    /// if fail, return false, you can get the erro infomation by:
    /// \code
    /// ErrorInfo info;
    /// ErrorInfoQueue queue;
    /// queue.getLastError(&info)
    /// qDebug() << info.errorNo() << info.errorMsg();
    /// \endcode
    /// \param model : QSqlQueryModel, Given by User and return to user.
    /// \param sql : QString. the sql sentence.
    /// \param connName : QString. the database name.
    /// \return true or false
    /// \author  Geniuswei
    /// \date 2015-06-12
    ///
    bool queryModel(QPQueryModel *model, const QString &sql, const QString &connName);
    bool queryModel(QPQueryModel *model, const QString &sql);
    ///
    /// \brief Execute query data row count in assigned table with assigned condition.\n
    /// if success, return the row count in table(>=0). \n
    /// if fail, return -1. you can get the erro infomation by:\n
    /// \code
    /// ErrorInfo info;
    /// ErrorInfoQueue queue;
    /// queue.getLastError(&info)
    /// qDebug() << info.errorNo() << info.errorMsg();
    /// \endcode
    /// \param tableName : QString. The table to query
    /// \param condition : QString. The query condition.
    /// \param connName : QString. the database name.
    /// \return row count : int.
    /// \author Geniuswei
    /// \date 2015-06-12
    int queryCount(const QString &tableName, const QString &condition) const;
    int queryCount(const QString &tableName, const QString &condition, const QString &connName) const;
    ///
    /// \brief Execute query data model by page from assigned tableName with assigend conditon\n
    /// then assign the data model to QSqlQueryModel.
    /// if success, return true \n
    /// if fail, return false. you can get the erro infomation by:\n
    /// \code
    /// ErrorInfo info;
    /// ErrorInfoQueue queue;
    /// queue.getLastError(&info)
    /// qDebug() << info.errorNo() << info.errorMsg();
    /// \endcode
    /// \param model : QSqlQueryModel, Given by user and return to user.
    /// \param tableName : QString. The table to query.
    /// \param index : int. the start position in table
    /// \param step : int. the rows to query
    /// \param conditon : QString. the query condition
    /// \return true/false
    /// \attention This function is virtual funtion. must be reinplemented by sub-class.
    /// \author Geniuswei
    /// \date 2015-06-12
    ///
//    virtual bool queryPageWithConnection(QueryModel *model, \
//                           const QString &tableName, \
//                           const int index, \
//                           const int step,
//                           const QString &conditon,\
//                           const QString &connName) = 0;
//    virtual bool queryPageWithConnection(QueryModel *model, \
//                           const QString &tableName, \
//                           const int index, \
//                           const int step,
//                           const QString &connName) = 0;
//    virtual bool queryPage(QueryModel *model, \
//                           const QString &tableName, \
//                           const int index, \
//                           const int step,
//                           const QString &conditon) = 0;
//    virtual bool queryPage(QueryModel *model, \
//                           const QString &tableName, \
//                           const int index, \
//                           const int step) = 0;
    virtual bool queryPage(QPQueryModel *model, \
                           const QString &tableName, \
                           const int index, \
                           const int step,
                           const QString &conditon,\
                           const QString &connName) = 0;
};

#endif // SQLCOMMAND_H
