#include "paonlinemodel.h"

PAOnlineModel::PAOnlineModel()
{
}

int PAOnlineModel::id() const
{
    return _id;
}

void PAOnlineModel::setId(int id)
{
    _id = id;
}
int PAOnlineModel::taskID() const
{
    return _taskID;
}

void PAOnlineModel::setTaskID(int taskID)
{
    _taskID = taskID;
}
QString PAOnlineModel::fileName() const
{
    return _fileName;
}

void PAOnlineModel::setFileName(const QString &fileName)
{
    _fileName = fileName;
}
QString PAOnlineModel::filePath() const
{
    return _filePath;
}

void PAOnlineModel::setFilePath(const QString &filePath)
{
    _filePath = filePath;
}
quint32 PAOnlineModel::fileSize() const
{
    return _fileSize;
}

void PAOnlineModel::setFileSize(const quint32 &fileSize)
{
    _fileSize = fileSize;
}
QByteArray PAOnlineModel::analysisJson() const
{
    return _analysisJson;
}

void PAOnlineModel::setAnalysisJson(const QByteArray &analysisJson)
{
    _analysisJson = analysisJson;
}
QByteArray PAOnlineModel::analysisXml() const
{
    return _analysisXml;
}

void PAOnlineModel::setAnalysisXml(const QByteArray &analysisXml)
{
    _analysisXml = analysisXml;
}
int PAOnlineModel::state() const
{
    return _state;
}

void PAOnlineModel::setState(int state)
{
    _state = state;
}
QDateTime PAOnlineModel::startTime() const
{
    return _startTime;
}

void PAOnlineModel::setStartTime(const QDateTime &startTime)
{
    _startTime = startTime;
}
QDateTime PAOnlineModel::endTime() const
{
    return _endTime;
}

void PAOnlineModel::setEndTime(const QDateTime &endTime)
{
    _endTime = endTime;
}

