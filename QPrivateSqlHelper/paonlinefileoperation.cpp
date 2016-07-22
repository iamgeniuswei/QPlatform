#include "paonlinefileoperation.h"
#include "paonlinemodel.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include "sqlerror.h"
PAOnlineFileOperation::PAOnlineFileOperation(QObject *parent)
    :QPOCIDataOperation(parent)
{
    setTableName("T_VIEW_FILE_ONLINE");
}
DBModel *PAOnlineFileOperation::QueryRecord(const int _id, const QString &connName)
{
    PAOnlineModel *online = new PAOnlineModel;
    QString sql = "SELECT * FROM T_DATA_FILE where ID = " + QString::number(_id,10);
    QSqlQuery query(sql);
    if(!(query.lastError().isValid()) && query.next() && online)
    {
        online->setId(query.value("ID").toInt());
        online->setFileName(query.value("FILENAME").toString());
        online->setFilePath(query.value("FILEPATH").toString());
        online->setFileSize(query.value("FILESIZE").toInt());
        online->setAnalysisJson(query.value("RSLTJSON").toByteArray());
        online->setAnalysisXml(query.value("RSLTXML").toByteArray());
        online->setState(query.value("STATE").toInt());
        online->setStartTime(query.value("STARTTIME").toDateTime());
        online->setEndTime(query.value("ENDTIME").toDateTime());
    }
    else
    {
        QPErrorInfoQueue *queue = QPErrorInfoQueue::getInstance();
        queue->addErrorInfo(SqlError::errNo_NoRecord, query.lastError().text());
        return NULL;
    }
    return online;

}
