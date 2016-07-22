#include "qpuistatusbar.h"
#include "private/qpuistatusbar_p.h"
#include <QGridLayout>
#include <QLabel>
#include <QStyleOption>
#include <QPainter>
QPUIStatusBar::QPUIStatusBar(QWidget *parent) : QPUIWidget(parent),
    d_ptr(new QPUIStatusBarPrivate(this))
{
    Q_D(QPUIStatusBar);
    d->init();
    initilizeUI();
    setMinimumWidth(1024);
    setFixedHeight(32);
}

void QPUIStatusBar::initilizeUI()
{
    Q_D(QPUIStatusBar);
    if(d->mainLayout)
    {
        if(d->versionLabel)
        {
            d->mainLayout->addWidget(d->versionLabel, 0, 1, 1, 1, Qt::AlignVCenter);
        }
//        if(d->logoLabel)
//        {
//            d->mainLayout->addWidget(d->logoLabel, 0, 3, 1, 1, Qt::AlignVCenter);
//        }
        setLayout(d->mainLayout);
    }
}

//void QPUIStatusBar::paintEvent(QPaintEvent *)
//{
//    QStyleOption opt;
//    opt.init(this);
//    QPainter p(this);
//    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
//}



void QPUIStatusBarPrivate::init()
{
    mainLayout = new QGridLayout(q_ptr);
    if(mainLayout)
    {
        mainLayout->setMargin(0);
        mainLayout->setColumnMinimumWidth(0, 10);
        mainLayout->setColumnMinimumWidth(4, 10);
        mainLayout->setColumnStretch(2, 1);
    }
    versionLabel = new QLabel(q_ptr);
    if(versionLabel)
    {
        versionLabel->setObjectName("SBVersionLabel");
    }
//    logoLabel = new QLabel(q_ptr);
//    if(logoLabel)
//    {
//        logoLabel->setObjectName("SBLogoLabel");
//    }
}
