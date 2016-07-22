#ifndef NONQUERYTHREAD_H
#define NONQUERYTHREAD_H
#include "qpsqlworkthread.h"
class DBModel;
class QPNonQueryThread : public QPSqlWorkThread
{
    Q_OBJECT
public:
    explicit QPNonQueryThread(QObject *parent = 0);
    void setNonQueryParameter(const QString &tableName, DBModel * const model);
    void setNonQueryParameter(const QString &tableName, const QString &connName, DBModel * const model);
protected:
    void run();

signals:

public slots:

private:
    DBModel *dModel;
    QString _tableOperation;
    QString _connName;

};

#endif // NONQUERYTHREAD_H
