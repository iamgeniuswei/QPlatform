#ifndef QOCISQLCOMMAND_H
#define QOCISQLCOMMAND_H
#include "qpsqlcommand.h"
class QPQueryModel;
class QPOCISqlCommand : public QPSqlCommand
{
public:
    QPOCISqlCommand();
    virtual bool queryPage(QPQueryModel *model, \
                           const QString &tableName, \
                           const int index, \
                           const int step,
                           const QString &conditon,\
                           const QString &connName);
//private:
//    bool queryPageWithConnection(QueryModel *model, \
//                           const QString &tableName, \
//                           const int index, \
//                           const int step,
//                           const QString &conditon,\
//                           const QString &connName);
//    bool queryPageWithConnection(QueryModel *model, \
//                           const QString &tableName, \
//                           const int index, \
//                           const int step,
//                           const QString &connName);
//    bool queryPage(QueryModel *model, \
//                           const QString &tableName, \
//                           const int index, \
//                           const int step,
//                           const QString &conditon);
//    bool queryPage(QueryModel *model, \
//                           const QString &tableName, \
//                           const int index, \
//                           const int step);
};

#endif // QOCISQLCOMMAND_H
