#include "qpuiview.h"
#include "private/qpuiview_p.h"
#include <QGridLayout>
QPUIView::QPUIView(QWidget *parent) : QPUIWidget(parent), d_ptr(new (std::nothrow) QPUIViewPrivate(this))
{
    Q_D(QPUIView);
    if(d)
    {
        d->init();
    }
}

void QPUIView::initilizeUI()
{
    Q_D(QPUIView);
    if(d && d->mainLayout)
    {
        setLayout(d->mainLayout);
    }
}

void QPUIView::addWidget(QWidget *widget, int row, int column, int rowSpan, int columnSpan, Qt::Alignment align)
{
    Q_D(QPUIView);
    if(widget && d)
    {
        if(d->mainLayout)
        {
            d->mainLayout->addWidget(widget, row, column, rowSpan, columnSpan, align);
        }
    }
}



void QPUIViewPrivate::init()
{
    mainLayout = new (std::nothrow) QGridLayout(q_ptr);
    if(mainLayout)
    {
        mainLayout->setMargin(0);
    }
}


QGridLayout *QPUIView::getLayout() const
{
    Q_D(const QPUIView);
    return d->mainLayout;
}

QPUIView::QPUIView(QPUIViewPrivate *dd, QWidget *parent):
    d_ptr(dd), QPUIWidget(parent)
{
    Q_D(QPUIView);
    if(d)
    {
        d->init();
    }
}
