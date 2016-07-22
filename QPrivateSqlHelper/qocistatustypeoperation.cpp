#include "qocistatustypeoperation.h"
#include "qpsqlconnection.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QStringList>
#include <QVariant>
#include "sqlerror.h"
QOCIStatusTypeOperation::QOCIStatusTypeOperation(QObject *parent)
    :QPOCIDataOperation(parent)
{
    setTableName("T_STATUSTYPE");
}

QStringList QOCIStatusTypeOperation::QueryRecordList(const QString &condition, const QString &connName)
{
    Q_UNUSED(condition);
    QStringList recordList;
    QString sql = "SELECT * FROM T_STATUSTYPE";
    if(!connName.isEmpty())
    {
        QSqlDatabase db = QPSqlConnection::getDBbyName("TaskDB");
        QSqlQuery query(sql, db);
        //if query success, only one row
        if(!query.lastError().isValid())
        {
            while(query.next())
            {
                recordList.append(query.value("STATUSTYPE_NAME").toString());
                recordList.append(query.value("STATUSTYPE_ID").toString());
            }

        }
        else
        {
            QPErrorInfoQueue *queue = QPErrorInfoQueue::getInstance();
            queue->addErrorInfo(SqlError::errNo_NoRecord, query.lastError().text());
            return recordList;
        }
    }
    return recordList;
}

