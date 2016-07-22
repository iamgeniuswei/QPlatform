#ifndef QUERYTHREAD_H
#define QUERYTHREAD_H
#include "qpsqlworkthread.h"
#include "sqlhelper_global.h"
class QPQueryThread : public QPSqlWorkThread
{
    Q_OBJECT
public:
    explicit QPQueryThread(QObject *parent = 0);
    void setQueryPageParameter(unsigned int index = 0,\
                                       unsigned int step = 100,\
                                       const QString &tableName = QString(),\
                                       const QString &condition = QString(),\
                                       const QString &realTable = QString(),\
                                       const QString &connName = QString());

//    void setQueryPageParameter(unsigned int index = 0,\
//                                       unsigned int step = 100,\
//                                       const QString &tableName = QString(),\
//                                       const QString &connName = QString());

//    void setQueryPageParameter(unsigned int index = 0,\
//                               unsigned int step = 100,\
//                               const QString &tableName = QString());

//    void setQueryPageParameter(unsigned int index = 0,\
//                               unsigned int step = 100,\
//                               const QString &tableName = QString(),\
//                               const QString &condition = QString());

//    virtual void setQueryCountParameterWithConnection(const QString &tableName = QString(),\
//                                const QString &condition = QString(),\
//                                const QString &connName = QString());
//    virtual void setQueryCountParameterWithConnection(const QString &tableName = QString(),\
//                                const QString &connName = QString());
//    virtual void setQueryCountParameter(const QString &tableName = QString());
    virtual void setQueryCountParameter(const QString &tableName = QString(),\
                                        const QString &condition = QString(),\
                                        const QString &realTable = QString(),\
                                        const QString &connName = QString());


    void setQueryRowParameter(const unsigned int _id, const QString &tableName = QString(), const QString &connName = QString());
    void setQueryRowParameter(const QString& conditon, const QString &tableName = QString(), const QString &connName = QString());
protected:
    ///
    /// \brief run
    /// override function, polymorphism
    /// execute three query function:
    /// 1) query page.
    /// 2) query count.
    /// 3) query row.
    void run();

private:
    void queryPage();
    void queryCount();
    void queryRow();
    void queryRowByCondition();
    void queryList();

private:
    QString _tableOperation;
    QString _queryModel;
    QString _realTable;
    QString _condition;
    QString _connName;
    unsigned int _index;
    unsigned int _step;
    unsigned int _rowId;
};

#endif // QUERYTHREAD_H
