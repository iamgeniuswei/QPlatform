#ifndef QPREALTIMECHART_H
#define QPREALTIMECHART_H

#include <QWidget>
#include "qpcharts_global.h"
class QPRealtimeChartPrivate;
class QPCHARTSSHARED_EXPORT QPRealtimeChart : public QWidget
{
    Q_OBJECT
public:
    explicit QPRealtimeChart(QWidget *parent = 0);
    void initilizeSignal();

signals:

public slots:
    void RealtimeDataShow();
private:
    QPRealtimeChartPrivate *const d_ptr;
    Q_DECLARE_PRIVATE(QPRealtimeChart)
};

#endif // QPREALTIMECHART_H
