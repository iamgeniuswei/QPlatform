#ifndef QPREALTIMECHART_P
#define QPREALTIMECHART_P
#include <QObject>
#include <QPen>
class QPRealtimeChart;
class QCustomPlot;
class QCPGraph;
class QCPAxis;
class QTimer;
class QHBoxLayout;
class QPRealtimeChartPrivate
{
public:
    QPRealtimeChartPrivate(QPRealtimeChart *parent):q_ptr(parent),
    plot(nullptr),graph(nullptr), xAxis(nullptr), yAxis(nullptr), timer(nullptr), mainLayout(nullptr){}
    void init();
public:
    QCustomPlot *plot;
    QCPGraph *graph;
    QCPAxis *xAxis, *yAxis;
    QString chartName;
    QPen pen;
    QTimer *timer;
    QHBoxLayout *mainLayout;
private:
    QPRealtimeChart *const q_ptr;
};

#endif // QPREALTIMECHART_P

