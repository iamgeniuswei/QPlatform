#ifndef PAONLINEMODEL_H
#define PAONLINEMODEL_H


#include "dbmodel.h"
#include "dbmodel_global.h"
#include <QString>
#include <QDateTime>
class DBMODELSHARED_EXPORT PAOnlineModel : public DBModel
{
public:
    PAOnlineModel();
    int id() const;
    void setId(int id);

    int taskID() const;
    void setTaskID(int taskID);

    QString fileName() const;
    void setFileName(const QString &fileName);

    QString filePath() const;
    void setFilePath(const QString &filePath);

    quint32 fileSize() const;
    void setFileSize(const quint32 &fileSize);

    QByteArray analysisJson() const;
    void setAnalysisJson(const QByteArray &analysisJson);

    QByteArray analysisXml() const;
    void setAnalysisXml(const QByteArray &analysisXml);

    int state() const;
    void setState(int state);

    QDateTime startTime() const;
    void setStartTime(const QDateTime &startTime);

    QDateTime endTime() const;
    void setEndTime(const QDateTime &endTime);

private:
    int _id;
    int _taskID;
    QString _fileName;
    QString _filePath;
    quint32 _fileSize;
    QByteArray _analysisJson;
    QByteArray _analysisXml;
    int _state;
    QDateTime _startTime;
    QDateTime _endTime;
};


#endif // PAONLINEMODEL_H
