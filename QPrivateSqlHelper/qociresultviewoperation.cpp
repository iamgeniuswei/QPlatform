#include "qociresultviewoperation.h"
#include "sysresultview.h"
#include "sqlerror.h"
#include <QSqlQuery>
#include <QDebug>
#include "qpsqlconnection.h"

QOCIResultViewOperation::QOCIResultViewOperation(QObject *parent)
    :QPOCIDataOperation(parent)
{
    setTableName("VIEW_RESULT_XYFX");
}

int QOCIResultViewOperation::InsertRecord(DBModel *)
{
    return 0;
}

int QOCIResultViewOperation::DeleteRecord(DBModel *)
{
    return 0;
}

int QOCIResultViewOperation::UpdateRecord(DBModel *)
{
    return 0;
}

DBModel *QOCIResultViewOperation::QueryRecord(const int _id, const QString &connName)
{
    Q_UNUSED(connName);
    SysResultView *resultViewInfo = new SysResultView;
    QString sql = "SELECT * FROM VIEW_RESULT_XYFX_ALL where RESULT_ID =" + QString::number(_id,10);
    QSqlDatabase db = QPSqlConnection::getDBbyName("TaskDB");
    QSqlQuery query(sql,db);
    //if query success, only one row
    if(!(query.lastError().isValid()) && query.next())
    {
        resultViewInfo->setResultId(query.value("RESULT_ID").toInt());
        resultViewInfo->setResultOriginid(query.value("RESULT_ORIGINID").toInt());
        resultViewInfo->setResultSeat(query.value("RESULT_SEAT").toInt());
        resultViewInfo->setResultObjectcode(query.value("RESULT_OBJECTCODE").toString());
        resultViewInfo->setResultContent(query.value("RESULT_CONTENT").toString());
        resultViewInfo->setResultReporter(query.value("RESULT_REPORTER").toString());
        resultViewInfo->setResultReporttime(query.value("RESULT_REPORTTIME").toDateTime());
        resultViewInfo->setResultDescription(query.value("RESULT_DESCRIPTION").toString());
        resultViewInfo->setResultStatus(query.value("RESULT_STATUS").toInt());
//        resultViewInfo->setResultEquipstatus(query.value("RESULT_EQUIPSTATUS").toInt());
//        resultViewInfo->setStatustypeId(query.value("STATUSTYPE_ID").toInt());
        resultViewInfo->setStatustypeName(query.value("STATUSTYPE_NAME").toString());
        resultViewInfo->setStatustypeData(query.value("STATUSTYPE_DATA").toInt());
//        resultViewInfo->setStatustypeDescription(query.value("STATUSTYPE_DESCRIPTION").toString());
//        resultViewInfo->setEquiptypeId(query.value("EQUIPTYPE_ID").toInt());
//        resultViewInfo->setEquiptypeName(query.value("EQUIPTYPE_NAME").toString());
//        resultViewInfo->setEquiptypeData(query.value("EQUIPTYPE_DATA").toInt());
//        resultViewInfo->setEquiptypeDescription(query.value("EQUIPTYPE_DESCRIPTION").toString());
    }
    else
    {
        QPErrorInfoQueue *queue = QPErrorInfoQueue::getInstance();
        queue->addErrorInfo(SqlError::errNo_NoRecord, query.lastError().text());
        return NULL;
    }
    return resultViewInfo;
}
