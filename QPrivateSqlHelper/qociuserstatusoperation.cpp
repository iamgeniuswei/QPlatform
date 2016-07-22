#include "qociuserstatusoperation.h"
#include "qpsqlconnection.h"
#include "userstatus.h"
#include "qperrorinfoqueue.h"
#include "sqlerror.h"
#include <QSqlQuery>
#include <QVariant>
QOCIUserStatusOperation::QOCIUserStatusOperation(QObject *parent) :
    QPOCIDataOperation(parent)
{
}

int QOCIUserStatusOperation::UpdateRecord(DBModel *dataModel, const QString &connName)
{
    UserStatus *userStatusInfo = dynamic_cast<UserStatus *>(dataModel);
    if(userStatusInfo)
    {
        QSqlDatabase db = QPSqlConnection::getDBbyName(connName);
        QSqlQuery query(db);
        if(userStatusInfo->inTime().isNull())
        {
            query.prepare("UPDATE T_USERSTATUS SET STATUS_ID=:STATUS_ID,LOGOUT_TIME=:LOGOUT_TIME where USERSTATUS_ID=:USERSTATUS_ID");
            query.bindValue(":USERSTATUS_ID",userStatusInfo->id());
            query.bindValue(":STATUS_ID",userStatusInfo->statusID());
            query.bindValue(":LOGOUT_TIME", userStatusInfo->outTime());
        }
        else
        {
            query.prepare("UPDATE T_USERSTATUS SET STATUS_ID=:STATUS_ID,LOGIN_TIME=:LOGIN_TIME,LOGOUT_TIME=:LOGOUT_TIME where USERSTATUS_ID=:USERSTATUS_ID");
            query.bindValue(":USERSTATUS_ID",userStatusInfo->id());
            query.bindValue(":STATUS_ID",userStatusInfo->statusID());
            query.bindValue(":LOGIN_TIME",userStatusInfo->inTime());
            query.bindValue(":LOGOUT_TIME", userStatusInfo->outTime());
        }
        return ExecuteQSqlQuery(query);
    }
    else
    {
        QPErrorInfoQueue *queue = QPErrorInfoQueue::getInstance();
        queue->addErrorInfo(SqlError::errNo_PointIsNULL, SqlError::errStr_PointIsNull);
        return SqlError::retInsertRecordError;
    }
}
