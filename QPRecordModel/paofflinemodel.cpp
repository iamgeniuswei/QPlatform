#include "paofflinemodel.h"

PAOfflineModel::PAOfflineModel()
{
}
int PAOfflineModel::id() const
{
    return _id;
}

void PAOfflineModel::setId(int id)
{
    _id = id;
}
int PAOfflineModel::taskID() const
{
    return _taskID;
}

void PAOfflineModel::setTaskID(int taskID)
{
    _taskID = taskID;
}
QString PAOfflineModel::fileName() const
{
    return _fileName;
}

void PAOfflineModel::setFileName(const QString &fileName)
{
    _fileName = fileName;
}
QString PAOfflineModel::filePath() const
{
    return _filePath;
}

void PAOfflineModel::setFilePath(const QString &filePath)
{
    _filePath = filePath;
}
quint32 PAOfflineModel::fileSize() const
{
    return _fileSize;
}

void PAOfflineModel::setFileSize(const quint32 &fileSize)
{
    _fileSize = fileSize;
}
QByteArray PAOfflineModel::analysisJson() const
{
    return _analysisJson;
}

void PAOfflineModel::setAnalysisJson(const QByteArray &analysisJson)
{
    _analysisJson = analysisJson;
}
QByteArray PAOfflineModel::analysisXml() const
{
    return _analysisXml;
}

void PAOfflineModel::setAnalysisXml(const QByteArray &analysisXml)
{
    _analysisXml = analysisXml;
}
int PAOfflineModel::state() const
{
    return _state;
}

void PAOfflineModel::setState(int state)
{
    _state = state;
}
QDateTime PAOfflineModel::startTime() const
{
    return _startTime;
}

void PAOfflineModel::setStartTime(const QDateTime &startTime)
{
    _startTime = startTime;
}
QDateTime PAOfflineModel::endTime() const
{
    return _endTime;
}

void PAOfflineModel::setEndTime(const QDateTime &endTime)
{
    _endTime = endTime;
}
int PAOfflineModel::fileType() const
{
    return _fileType;
}

void PAOfflineModel::setFileType(int fileType)
{
    _fileType = fileType;
}
QString PAOfflineModel::sourceType() const
{
    return _sourceType;
}

void PAOfflineModel::setSourceType(const QString &sourceType)
{
    _sourceType = sourceType;
}
QString PAOfflineModel::clientPath() const
{
    return _clientPath;
}

void PAOfflineModel::setClientPath(const QString &clientPath)
{
    _clientPath = clientPath;
}













