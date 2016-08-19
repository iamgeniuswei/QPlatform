#include "qpuititlebar.h"
#include "private/qpuititlebar_p.h"
#include <QGridLayout>
#include <QMouseEvent>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
QPUITitleBar::QPUITitleBar(QWidget *parent) : QPUIWidget(parent),d_ptr(new QPUITitleBarPrivate(this))
{
    Q_D(QPUITitleBar);
    setMinimumHeight(48);
    d->init();
}

void QPUITitleBar::addTitleLogo(QLabel *logo)
{
    Q_D(QPUITitleBar);
    if(logo && d->mainLayout)
    {
        d->mainLayout->addWidget(logo, 0, 1, 3, 1, Qt::AlignVCenter);
    }
}

void QPUITitleBar::addTitleText(QWidget *text)
{
    Q_D(QPUITitleBar);
    if(text && d->mainLayout)
    {
        d->mainLayout->addWidget(text, 0, 2, 3, 1, Qt::AlignVCenter);
    }
}

void QPUITitleBar::addSubTitleText(QLabel *text)
{
    Q_D(QPUITitleBar);
    if(text && d->mainLayout)
    {
        d->mainLayout->addWidget(text, 2, 3, 1, 1, Qt::AlignTop);
    }
}

void QPUITitleBar::addSysBtn(QPushButton *sysBtn)
{
    Q_D(QPUITitleBar);
    if(sysBtn)
    {
        if(d->systemLayout)
        {
            d->systemLayout->addWidget(sysBtn);
        }
        else
        {
            d->systemLayout = new QHBoxLayout;
            if(d->systemLayout)
                d->systemLayout->addWidget(sysBtn);
        }
    }
}

void QPUITitleBar::addCustomBtn(QWidget *customBtn)
{
    Q_D(QPUITitleBar);
    if(customBtn)
    {
        if(d->customLayout)
        {
            d->customLayout->addWidget(customBtn, 0, Qt::AlignVCenter|Qt::AlignCenter);
        }
        else
        {
            d->customLayout = new QHBoxLayout;
            if(d->customLayout)
            {
                d->customLayout->setMargin(0);
                d->customLayout->addWidget(customBtn, 0, Qt::AlignVCenter|Qt::AlignCenter);
            }
        }
    }
}

void QPUITitleBar::setParent(QWidget *parent)
{
    Q_D(QPUITitleBar);
    d->parentWindow = parent;
    //TODO: setParent
//    QWidget::setParent(parent);
}

void QPUITitleBar::initilizeUI()
{
    Q_D(QPUITitleBar);
    if(d->mainLayout)
    {
        if(d->customLayout)
        {
            d->mainLayout->addLayout(d->customLayout, 1, 5, 2, 1, Qt::AlignBottom);
        }
        if(d->systemLayout)
        {
            d->mainLayout->addLayout(d->systemLayout, 0, 7, 1, 1);
        }
        setLayout(d->mainLayout);
    }
}

void QPUITitleBar::mousePressEvent(QMouseEvent *event)
{
    Q_D(QPUITitleBar);
    if(event->button() == Qt::LeftButton)
    {
        d->mousePress = true;
    }
    d->moveDistance = event->globalPos() - pos();
}

void QPUITitleBar::mouseMoveEvent(QMouseEvent *event)
{
    Q_D(QPUITitleBar);
    if(d->mousePress  && d->windowMove)
    {
        QPoint movePos = event->globalPos();
        if(d->parentWindow)
        {
            d->parentWindow->move(d->parentWindow->pos() + movePos - d->moveDistance);
            d->moveDistance = movePos;
        }
        else
            move(movePos - d->moveDistance);
    }
}

void QPUITitleBar::mouseReleaseEvent(QMouseEvent *)
{
    Q_D(QPUITitleBar);
    d->mousePress = false;
}


void QPUITitleBarPrivate::init()
{
    mainLayout = new QGridLayout(q_ptr);
    if(mainLayout)
    {
        mainLayout->setMargin(1);
        mainLayout->setColumnMinimumWidth(0, 10);
        mainLayout->setColumnMinimumWidth(1, 10);
        mainLayout->setColumnMinimumWidth(2, 50);
        mainLayout->setColumnStretch(3, 1);
        mainLayout->setColumnMinimumWidth(3, 30);
    }
}
