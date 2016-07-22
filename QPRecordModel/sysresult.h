#ifndef SYSRESULT_H
#define SYSRESULT_H

#include "dbmodel_global.h"
#include "dbmodel.h"
#include <QString>
#include <QDateTime>

class DBMODELSHARED_EXPORT SysResult : public DBModel
{
public:


    int getResultId() const;
    void setResultId(int value);

    int getResultApplyId() const;
    void setResultApplyId(int value);

    QString getResultContent() const;
    void setResultContent(const QString &value);

    QString getResultDescription() const;
    void setResultDescription(const QString &value);

    int getResultStatus() const;
    void setResultStatus(int value);

    int getResultSeat() const;
    void setResultSeat(int value);

    int getResultSchedule() const;
    void setResultSchedule(int value);

    QDateTime getResultReportTime() const;
    void setResultReportTime(const QDateTime &value);

private:
    int resultId;
    int resultApplyId;
    QString resultContent;
    QString resultDescription;
    int resultStatus;
    int resultSeat;
    int resultSchedule;
    QDateTime resultReportTime;
};

#endif // SYSRESULT_H
