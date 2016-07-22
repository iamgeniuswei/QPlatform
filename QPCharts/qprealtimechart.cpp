#include "qprealtimechart.h"
#include "private/qprealtimechart_p.h"
#include "qcustomplot.h"
#include <QDebug>
#include <QTimer>
#include <QDateTime>
#include <QtGlobal>
#include <QHBoxLayout>
QPRealtimeChart::QPRealtimeChart(QWidget *parent) : QWidget(parent),
    d_ptr(new QPRealtimeChartPrivate(this))
{
    Q_D(QPRealtimeChart);
    d->init();
    if(d->timer)
    {
        connect(d->timer, &QTimer::timeout, this, &QPRealtimeChart::RealtimeDataShow);
        d->timer->start(1000);
    }


}

void QPRealtimeChart::initilizeSignal()
{
    Q_D(QPRealtimeChart);
    if(d->xAxis)
    {
//        connect(d->xAxis, &QCPAxis::rangeChanged(QCPRange), )
    }
}

void QPRealtimeChart::RealtimeDataShow()
{
    Q_D(QPRealtimeChart);
    double key = QDateTime::currentDateTime().toMSecsSinceEpoch() / 1000.0;
    static double lastPointKey = 0;
//    if(key - lastPointKey > 0.01)
//    {
        double yValue = qrand() % 100;
        if(d->graph)
        {
            d->graph->addData(key, yValue);
            d->graph->rescaleValueAxis();
        }
        lastPointKey = key;
//    }
    if(d->xAxis)
    {
        d->xAxis->setRange(key, 20, Qt::AlignRight);
    }
    if(d->plot)
        d->plot->replot();

}



void QPRealtimeChartPrivate::init()
{
    timer = new QTimer(q_ptr);
    plot = new (std::nothrow) QCustomPlot(q_ptr);
    if(plot)
    {
        graph = plot->addGraph();
        if(!graph)
        {
            qWarning() << "add Graph failed";
            return;
        }
        //initilize QPen;
        pen.setColor(QColor(236, 110, 0));
        pen.setWidth(2);
        pen.setStyle(Qt::SolidLine);

        //initilize QCPGraph
        graph->setPen(pen);
        graph->setBrush(QBrush(QColor(236, 110, 0, 80)));
        graph->setLineStyle(QCPGraph::lsLine);
        graph->setScatterStyle(QCPScatterStyle::ssCircle);
        graph->setName("Real time Data");

        //initilize QCPAxies;
        xAxis = plot->xAxis;
        yAxis = plot->yAxis;
        if(!xAxis || !yAxis)
        {
            qWarning() << "Axies failed";
            return;
        }
        xAxis->setBasePen(QPen(Qt::white));
        xAxis->setTickPen(QPen(Qt::white));
        xAxis->setSubTickPen(QPen(Qt::white));
        xAxis->setTickLabelColor(Qt::white);
        yAxis->setBasePen(QPen(Qt::white));
        yAxis->setTickPen(QPen(Qt::white));
        yAxis->setSubTickPen(QPen(Qt::white));
        yAxis->setTickLabelColor(Qt::white);
        xAxis->setTickLabelType(QCPAxis::ltDateTime);
        xAxis->setTickLabelRotation(60);
        xAxis->setDateTimeFormat("hh:mm:ss");

        xAxis->setAutoTickStep(false);
        xAxis->setAutoSubTicks(false);
        xAxis->setTickStep(1);
        xAxis->setSubTickCount(0);



        QLinearGradient plotGradient;
        plotGradient.setStart(0, 0);
        plotGradient.setFinalStop(0, 350);
        plotGradient.setColorAt(0, QColor(80, 80, 80));
        plotGradient.setColorAt(1, QColor(50, 50, 50));
        plot->setBackground(plotGradient);
        QLinearGradient axisRectGradient;
        axisRectGradient.setStart(0, 0);
        axisRectGradient.setFinalStop(0, 350);
        axisRectGradient.setColorAt(0, QColor(80, 80, 80));
        axisRectGradient.setColorAt(1, QColor(30, 30, 30));
//        plot->axisRect()->setBackground(axisRectGradient);
        plot->setBackground(axisRectGradient);
    }
    mainLayout = new QHBoxLayout(q_ptr);
    if(mainLayout)
    {
        mainLayout->setMargin(0);
        mainLayout->addWidget(plot);
        q_ptr->setLayout(mainLayout);
    }
}
