#ifndef QPCHARTS_P
#define QPCHARTS_P
#include <QObject>
class QPCharts;
class QCustomPlot;
class QCPAxis;
class QCPAbstractPlottable;
class QHBoxLayout;
class QPChartsPrivate
{
public:
    QPChartsPrivate(QPCharts *parent = 0) :
    q_ptr(parent)
    {}
    QString chartName;
    QCustomPlot *mainPlot;
    QCPAbstractPlottable *graph;
    QCPAxis *xAxis, *yAxis, *xAxis2, *yAxis2;
    QPen axisPen;

    uint isAutoTick : 1;
    uint isAutoSubTick : 1;






    //may be removed.
    QPen graphPen;
    QBrush graphBrush;
    QHBoxLayout *mainLayout;
private:


private:
    QPCharts *const q_ptr;
};

#endif // QPCHARTS_P

