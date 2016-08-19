#include "qpsqlsqlcommand.h"

QPSQLSqlCommand::QPSQLSqlCommand()
{

}

bool QPSQLSqlCommand::queryPage(QPQueryModel *model, const QString &tableName, const int index, const int step, const QString &conditon, const QString &connName)
{
    QString sql;
    if(conditon.isEmpty())
    {
        sql = QString("SELECT * FROM " + tableName + " LIMIT %1 OFFSET %2").arg(QString::number(step)).arg(QString::number(index));
    }
    else
    {

        sql = QString("SELECT * FROM " + tableName + " WHERE " + conditon + " LIMIT %1 OFFSET %2").arg(QString::number(step)).arg(QString::number(index));

    }
    return queryModel(model, sql, connName);
}
