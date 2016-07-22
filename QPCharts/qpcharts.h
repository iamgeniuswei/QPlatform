#ifndef QPCHARTS_H
#define QPCHARTS_H

#include <QWidget>
#include "qpcharts_global.h"
class QCustomPlot;
class QCPAbstractPlottable;
class QPCHARTSSHARED_EXPORT QPCharts : public QWidget
{
    Q_OBJECT
public:
    explicit QPCharts(QWidget *parent = 0);
    enum CHARTTYPE{
        LINE,
        BAR
    };
    Q_ENUM(CHARTTYPE)
    void initilizeUI();
    QCustomPlot *plot() const;
    QCPAbstractPlottable *graph() const;
public slots:

};

#endif // QPCHARTS_H
