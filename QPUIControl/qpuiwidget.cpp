#include "qpuiwidget.h"
#include "private/qpuiwidget_p.h"
#include <QPainter>

//TODO
#include <QStyleOption>
QPUIWidget::QPUIWidget(QWidget *parent) : QWidget(parent),
    d_ptr(new QPUIWidgetPrivate)
{
    setWindowFlags(Qt::FramelessWindowHint);
//    setFixedSize(1680,1050);
//    setAttribute(Qt::WA_TranslucentBackground);
}

QPUIWidget::~QPUIWidget()
{

}

void QPUIWidget::initilizeUI()
{

}

void QPUIWidget::initilizeSignal()
{

}

void QPUIWidget::initilizeThread()
{

}

int QPUIWidget::xRadius() const
{
    Q_D(const QPUIWidget);
    return d->xRadius;
}

void QPUIWidget::setXRadius(const int _xRadius)
{
    Q_D(QPUIWidget);
    d->xRadius = _xRadius;
}

int QPUIWidget::yRadius() const
{
    Q_D(const QPUIWidget);
    return d->yRadius;
}

void QPUIWidget::setYRadius(const int _yRadius)
{
    Q_D(QPUIWidget);
    d->yRadius = _yRadius;
}

QColor QPUIWidget::borderColor() const
{
    Q_D(const QPUIWidget);
    return d->borderColor;
}

void QPUIWidget::setBorderColor(const QColor &_borderColor)
{
    Q_D(QPUIWidget);
    d->borderColor = _borderColor;
}

int QPUIWidget::widgetMinHeight() const
{
    Q_D(const QPUIWidget);
    return d->widgetMinHeight;
}

void QPUIWidget::setWidgetMinHeight(const int _widgetHeight)
{
    Q_D(QPUIWidget);
    d->widgetMinHeight = _widgetHeight;
    setMinimumHeight(d->widgetMinHeight);
    updateGeometry();
}

int QPUIWidget::widgetMinWidth() const
{
    Q_D(const QPUIWidget);
    return d->widgetMinWidth;
}

void QPUIWidget::setWidgetMinWidth(const int _widgetWidth)
{
    Q_D(QPUIWidget);
    d->widgetMinWidth = _widgetWidth;
    setMinimumWidth(d->widgetMinWidth);
    updateGeometry();
}

void QPUIWidget::paintEvent(QPaintEvent *)
{
//    Q_D(QPUIWidget);
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
//    QPainter painter(this);
//    painter.setRenderHint(QPainter::Antialiasing, true);
////    painter.setPen(d->borderColor);
//    painter.drawRoundedRect(this->rect(), d->xRadius, d->yRadius);
}

//QSize QPUIWidget::sizeHint() const
//{
//    return QSize(1024, 768);
//}

