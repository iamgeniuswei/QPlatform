#include "qpstaffgauge.h"
#include "private/qpstaffgauge_p.h"
QPStaffGauge::QPStaffGauge(QObject *parent) : QObject(parent), d_ptr(new QPStaffGaugePrivate(this))
{
    Q_D(QPStaffGauge);
    d->init();
}

void QPStaffGauge::setShowHorizonLine(bool show)
{
    Q_D(QPStaffGauge);
    d->showHorizontalLine = show;
}

bool QPStaffGauge::showHorizonLine() const
{
    Q_D(const QPStaffGauge);
    return d->showHorizontalLine;
}

void QPStaffGauge::setShowVerticalLine(bool show)
{
    Q_D(QPStaffGauge);
    d->showVerticalLine = show;
}

bool QPStaffGauge::showVerticalLine() const
{
    Q_D(const QPStaffGauge);
    return d->showVerticalLine;
}

void QPStaffGauge::setShowHorizonLabel(bool show)
{
    Q_D(QPStaffGauge);
    d->showHorizontalLabel = show;
}

bool QPStaffGauge::showHorizonLabel() const
{
    Q_D(const QPStaffGauge);
    return d->showHorizontalLabel;
}

void QPStaffGauge::setShowVerticalLabel(bool show)
{
    Q_D(QPStaffGauge);
    d->showVerticalLabel = show;
}

bool QPStaffGauge::showVerticalLabel() const
{
    Q_D(const QPStaffGauge);
    return d->showVerticalLabel;
}

void QPStaffGauge::setLinePen(const QPen &pen)
{
    Q_D(QPStaffGauge);
    d->linePen = pen;
}

QPen QPStaffGauge::linePen() const
{
    Q_D(const QPStaffGauge);
    return d->linePen;
}

void QPStaffGauge::setLabelPen(const QPen &pen)
{
    Q_D(QPStaffGauge);
    d->labelPen = pen;
}

QPen QPStaffGauge::labelPen() const
{
    Q_D(const QPStaffGauge);
    return d->labelPen;
}

void QPStaffGauge::setVerticalLabel(const QString &text)
{
    Q_D(QPStaffGauge);
    d->verticalLabel = text;
}

QString QPStaffGauge::verticalLabel() const
{
    Q_D(const QPStaffGauge);
    return d->verticalLabel;
}

void QPStaffGauge::setHorizonLabel(const QString &text)
{
    Q_D(QPStaffGauge);
    d->horizonLabel = text;
}

QString QPStaffGauge::horizonLabel() const
{
    Q_D(const QPStaffGauge);
    return d->horizonLabel;
}





void QPStaffGaugePrivate::init()
{
    linePen.setWidth(1);
    linePen.setColor(Qt::red);
    labelPen.setWidth(1);
    labelPen.setColor(Qt::red);
#ifdef WIN32
    labelFont.setFamily("Courier New");
    labelFont.setPixelSize(9);
#endif

}
