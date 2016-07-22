#include "qpuistaticallabel.h"
#include "private/qpuistaticallabel_p.h"
#include <QLabel>
#include <QMouseEvent>
QPUIStaticalLabel::QPUIStaticalLabel(QWidget *parent) : QPUIView(new QPUIStaticalLabelPrivate(this) ,parent)
{
    Q_D(QPUIStaticalLabel);
    if(d)
    {
        d->init();
        initilizeUI();
    }
}

void QPUIStaticalLabel::initilizeUI()
{
    Q_D(QPUIStaticalLabel);
    addWidget(d->staticalType, 0, 0, 1, 1);
    addWidget(d->staticalData, 1, 0, 1, 1);
    setFixedSize(120, 100);
    QPUIView::initilizeUI();
}

void QPUIStaticalLabel::setStaticalValue(const int value)
{
    Q_D(QPUIStaticalLabel);
    d->staticalValue = value;
    setStaticalData(value);
}

void QPUIStaticalLabel::setStaticalType(const QString &type)
{
    Q_D(QPUIStaticalLabel);
    if(d && d->staticalType)
        d->staticalType->setText(type);
}

void QPUIStaticalLabel::setStaticalData(const int value)
{
    Q_D(QPUIStaticalLabel);
    if(d->staticalData)
    {
        d->staticalData->setText(QString::number(value));
    }
}

void QPUIStaticalLabel::mousePressEvent(QMouseEvent *e)
{
    setCursor(Qt::PointingHandCursor);

}

void QPUIStaticalLabel::mouseReleaseEvent(QMouseEvent *)
{
    unsetCursor();
}



void QPUIStaticalLabelPrivate::init()
{
    staticalType = new (std::nothrow) QLabel(q_ptr);
    staticalData = new (std::nothrow) QLabel(q_ptr);
    if(staticalType)
    {
        staticalType->setObjectName("staticalType");
    }
    if(staticalData)
    {
        staticalData->setObjectName("staticalData");
    }
}
