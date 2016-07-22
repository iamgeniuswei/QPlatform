#include "paofflinefileoperation.h"
#include "paofflinemodel.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include "sqlerror.h"
PAOfflineFileOperation::PAOfflineFileOperation(QObject *parent)
    :QPOCIDataOperation(parent)
{
    setTableName("T_VIEW_FILE_OFFLINE");
}

DBModel *PAOfflineFileOperation::QueryRecord(const int _id, const QString &connName)
{
    PAOfflineModel *offlineFile = new PAOfflineModel;
    QString sql = "SELECT * FROM T_DATA_FILE_OFFLINE where ID = " + QString::number(_id,10);
    QSqlQuery query(sql);
    if(!(query.lastError().isValid()) && query.next() && offlineFile)
    {
        offlineFile->setId(query.value("ID").toInt());
        offlineFile->setFileName(query.value("FILENAME").toString());
        offlineFile->setFilePath(query.value("FILEPATH").toString());
        offlineFile->setFileSize(query.value("FILESIZE").toInt());
        offlineFile->setAnalysisJson(query.value("RSLTJSON").toByteArray());
        offlineFile->setAnalysisXml(query.value("RSLTXML").toByteArray());
        offlineFile->setState(query.value("STATE").toInt());
        offlineFile->setStartTime(query.value("STARTTIME").toDateTime());
        offlineFile->setEndTime(query.value("ENDTIME").toDateTime());
        offlineFile->setClientPath(query.value("CLIENTPATH").toString());
    }
    else
    {
        QPErrorInfoQueue *queue = QPErrorInfoQueue::getInstance();
        queue->addErrorInfo(SqlError::errNo_NoRecord, query.lastError().text());
        return NULL;
    }
    return offlineFile;

}
