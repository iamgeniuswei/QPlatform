#ifndef SYSRESULTVIEW_H
#define SYSRESULTVIEW_H
#include "dbmodel_global.h"
#include "dbmodel.h"
#include <QDateTime>
#include <QString>
class DBMODELSHARED_EXPORT SysResultView : public DBModel
{
public:

    int getResultId() const;
    void setResultId(int value);

    int getResultOriginid() const;
    void setResultOriginid(int value);

    QString getResultObjectcode() const;
    void setResultObjectcode(const QString &value);

    QString getResultContent() const;
    void setResultContent(const QString &value);

    QString getResultReporter() const;
    void setResultReporter(const QString &value);

    QDateTime getResultReporttime() const;
    void setResultReporttime(const QDateTime &value);

    QString getResultDescription() const;
    void setResultDescription(const QString &value);

    int getResultStatus() const;
    void setResultStatus(int value);

    int getResultSeat() const;
    void setResultSeat(int value);

    int getResultEquipstatus() const;
    void setResultEquipstatus(int value);

    int getStatustypeId() const;
    void setStatustypeId(int value);

    QString getStatustypeName() const;
    void setStatustypeName(const QString &value);

    int getStatustypeData() const;
    void setStatustypeData(int value);

    QString getStatustypeDescription() const;
    void setStatustypeDescription(const QString &value);

    int getEquiptypeId() const;
    void setEquiptypeId(int value);

    QString getEquiptypeName() const;
    void setEquiptypeName(const QString &value);

    int getEquiptypeData() const;
    void setEquiptypeData(int value);

    QString getEquiptypeDescription() const;
    void setEquiptypeDescription(const QString &value);

private:
    int resultId;
    int resultOriginid;
    QString resultObjectcode;
    QString resultContent;
    QString resultReporter;
    QDateTime resultReporttime;
    QString resultDescription;
    int resultStatus;
    int resultSeat;
    int resultEquipstatus;
    int statustypeId;
    QString statustypeName;
    int statustypeData;
    QString statustypeDescription;
    int equiptypeId;
    QString equiptypeName;
    int equiptypeData;
    QString equiptypeDescription;
};

#endif // SYSRESULTVIEW_H
