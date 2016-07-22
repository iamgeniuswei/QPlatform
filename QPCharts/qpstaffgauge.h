#ifndef QPSTAFFGAUGE_H
#define QPSTAFFGAUGE_H

#include <QObject>
class QPStaffGaugePrivate;
class QPStaffGauge : public QObject
{
    Q_OBJECT
public:
    explicit QPStaffGauge(QObject *parent = 0);

    void setShowHorizonLine(bool show);
    bool showHorizonLine() const;

    void setShowVerticalLine(bool show);
    bool showVerticalLine() const;

    void setShowHorizonLabel(bool show);
    bool showHorizonLabel() const;

    void setShowVerticalLabel(bool show);
    bool showVerticalLabel() const;

    void setLinePen(const QPen &pen);
    QPen linePen() const;

    void setLabelPen(const QPen &pen);
    QPen labelPen() const;

    void setVerticalLabel(const QString &text);
    QString verticalLabel() const;

    void setHorizonLabel(const QString &text);
    QString horizonLabel() const;
signals:

public slots:

private:
    QPStaffGaugePrivate *const d_ptr;
    Q_DECLARE_PRIVATE(QPStaffGauge)
};

#endif // QPSTAFFGAUGE_H
