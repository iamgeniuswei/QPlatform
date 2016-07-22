#include "qpocidataoperation.h"
#include "qpsqlcommand.h"
#include "qpocisqlcommand.h"
#include "sqlerror.h"
#include "qpquerymodel.h"
#include <QSqlQuery>

QPOCIDataOperation::QPOCIDataOperation(QObject *parent)
    :QPDataOperation(parent)
{

}

bool QPOCIDataOperation::QueryPage(QPQueryModel *model, int index, int step, const QString &condition, const QString &connName)
{
    QPSqlCommand *command = NULL;
    command = new QPOCISqlCommand;
    if(command)
    {
        if(command->queryPage(model, tableName(), index, step, condition, connName))
        {
            delete command;
            command = NULL;
            return true;
        }
        else
        {
            delete command;
            command = NULL;
            return false;
        }
    }
    return true;
}

//bool QPOCIDataOperation::QueryPage(QueryModel *model, int index, int step, const QString &condition)
//{
//    SqlCommand *command = NULL;
//    command = new QOCISqlCommand;
//    if(command)
//    {
//        if(command->queryPage(model,tableName(), index, step, condition))
//        {
//            delete command;
//            command = NULL;
//            return true;
//        }
//        else
//        {
//            delete command;
//            command = NULL;
//            return false;
//        }
//    }
//    return true;
//}

int QPOCIDataOperation::QueryCount(const QString &condition, const QString &connName)
{
    QPSqlCommand *command = NULL;
    command = new QPOCISqlCommand;
    if(command)
    {

        int count = command->queryCount(tableName(), condition, connName);
        delete command;
        command = NULL;
        return count;
    }
    else
    {
        return SqlError::retNO_ERROR;
    }
}

//int QPOCIDataOperation::QueryCount(const QString &condition)
//{
//    SqlCommand *command = NULL;
//    command = new QOCISqlCommand;
//    if(command)
//    {

//        int count = command->queryCount(tableName(), condition);
//        delete command;
//        command = NULL;
//        return count;
//    }
//    else
//    {
//        return SqlError::retNO_ERROR;
//    }
//}

//int QPOCIDataOperation::InsertRecord(DBModel *dataModel)
//{
//    Q_UNUSED(dataModel);
//    return SqlError::retNO_SUCCESS;
//}

int QPOCIDataOperation::InsertRecord(DBModel *dataModel, const QString &connName)
{
    Q_UNUSED(dataModel);
    Q_UNUSED(connName);
    return SqlError::retNO_ERROR;
}

int QPOCIDataOperation::DeleteRecord(DBModel *dataModel, const QString &connName)
{
    Q_UNUSED(dataModel);
    Q_UNUSED(connName);
    return SqlError::retNO_ERROR;
}

int QPOCIDataOperation::UpdateRecord(DBModel *dataModel, const QString &connName)
{
    Q_UNUSED(dataModel);
    Q_UNUSED(connName);
    return SqlError::retNO_ERROR;
}

//int QPOCIDataOperation::DeleteRecord(DBModel *dataModel)
//{
//    Q_UNUSED(dataModel);
//    return SqlError::retNO_SUCCESS;
//}

//int QPOCIDataOperation::UpdateRecord(DBModel *dataModel)
//{
//    Q_UNUSED(dataModel);
//    return SqlError::retNO_SUCCESS;
//}

//DBModel *QPOCIDataOperation::QueryRecord(int _id)
//{
//    Q_UNUSED(_id);
//    return NULL;
//}

DBModel *QPOCIDataOperation::QueryRecord(const int _id, const QString &connName)
{
    Q_UNUSED(_id);
    Q_UNUSED(connName);
    return NULL;
}

//DBModel *QPOCIDataOperation::QueryRecord(const QString &condition)
//{
//    Q_UNUSED(condition);
//    return NULL;
//}

DBModel *QPOCIDataOperation::QueryRecord(const QString &condition, const QString &connName)
{
    Q_UNUSED(condition);
    Q_UNUSED(connName);
    return NULL;
}

QStringList QPOCIDataOperation::QueryRecordList(const QString &condition, const QString &connName)
{
    QStringList list;
    Q_UNUSED(condition);
    Q_UNUSED(connName);
    return list;
}


int QPOCIDataOperation::ExecuteQSqlQuery(QSqlQuery &query)
{
    QPSqlCommand *command = new QPOCISqlCommand;
    int rowsAffected = command->execQSqlQuery(query);
    delete command;
    command = NULL;
    return rowsAffected;
}

int QPOCIDataOperation::ExecuteSql(const QString &sql, const QString &connName)
{
    QPSqlCommand *command = new QPOCISqlCommand;
    int rowDeleted = command->execNoQuerySQL(sql,connName);
    delete command;
    command = NULL;
    return rowDeleted;

}

