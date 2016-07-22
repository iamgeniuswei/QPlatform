#include "qocisoftwarestatus.h"
#include "qpsqlconnection.h"
#include "softwarestatus.h"
#include "qperrorinfoqueue.h"
#include "sqlerror.h"
#include <QSqlQuery>
#include <QVariant>
QOCISoftwareStatusOperation::QOCISoftwareStatusOperation(QObject *parent) :
    QPOCIDataOperation(parent)
{
}

int QOCISoftwareStatusOperation::UpdateRecord(DBModel *dataModel, const QString &connName)
{
    SoftwareStatus *softInfo = dynamic_cast<SoftwareStatus *>(dataModel);
    if(softInfo)
    {
        QSqlDatabase db = QPSqlConnection::getDBbyName(connName);
        QSqlQuery query(db);
        if(softInfo->inTime().isNull())
        {
            query.prepare("UPDATE T_SOFTWARESTATUS SET SOFTWARE_STATUSID=:SOFTWARE_STATUSID,SOFTWARE_LOGOUT_TIME=:SOFTWARE_LOGOUT_TIME where SOFTWARESTATUS_ID=:SOFTWARESTATUS_ID");
            query.bindValue(":SOFTWARESTATUS_ID",softInfo->id());
            query.bindValue(":SOFTWARE_STATUSID",softInfo->statusID());
            query.bindValue(":SOFTWARE_LOGOUT_TIME", softInfo->outTime());
        }
        else
        {
            query.prepare("UPDATE T_SOFTWARESTATUS SET SOFTWARE_STATUSID=:SOFTWARE_STATUSID,SOFTWARE_LOGIN_TIME=:SOFTWARE_LOGIN_TIME,SOFTWARE_LOGOUT_TIME=:SOFTWARE_LOGOUT_TIME where SOFTWARESTATUS_ID=:SOFTWARESTATUS_ID");
            query.bindValue(":SOFTWARESTATUS_ID",softInfo->id());
            query.bindValue(":SOFTWARE_STATUSID",softInfo->statusID());
            query.bindValue(":SOFTWARE_LOGIN_TIME",softInfo->inTime());
            query.bindValue(":SOFTWARE_LOGOUT_TIME", softInfo->outTime());
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
