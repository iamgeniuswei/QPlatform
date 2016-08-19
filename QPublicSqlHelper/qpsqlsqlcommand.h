#ifndef QPSQLSQLCOMMAND_H
#define QPSQLSQLCOMMAND_H

#include "qpsqlcommand.h"
class QPSQLSqlCommand : public QPSqlCommand
{
public:
    QPSQLSqlCommand();
    bool queryPage(QPQueryModel *model, const QString &tableName, const int index, const int step, const QString &conditon, const QString &connName);
};

#endif // QPSQLSQLCOMMAND_H
