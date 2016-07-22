#include "qpuiwindow.h"
#include "private/qpuiwindow_p.h"
#include <QGridLayout>
#include <QSplitter>
#include "qpuititle.h"
#include "qpuinavigationbar.h"
#include "qpuistatusbar.h"
QPUIWindow::QPUIWindow(QWidget *parent) : QPUIWidget(parent),d_ptr(new QPUIWindowPrivate(this))
{
    Q_D(QPUIWindow);
    d->init();
}

void QPUIWindow::addTitle(QPUITitle *title)
{
    Q_D(QPUIWindow);
    if(title && d->mainLayout)
    {
        d->mainLayout->addWidget(title, 0, 0, 1, 1, Qt::AlignTop);
    }
}

void QPUIWindow::addNavigationBar(QPUINavigationBar *navigationBar)
{
    Q_D(QPUIWindow);
    if(navigationBar && d->mainSplitter)
    {
        d->mainSplitter->addWidget(navigationBar);
    }
}

void QPUIWindow::addContentArea(QWidget *contentArea)
{
    Q_D(QPUIWindow);
    if(contentArea && d->mainLayout)
    {
        d->mainLayout->addWidget(contentArea, 1, 0, 1, 1/*, Qt::AlignCenter*/);
    }
}

void QPUIWindow::addStatusBar(QPUIStatusBar *statusBar)
{
    Q_D(QPUIWindow);
    if(statusBar && d->mainLayout)
    {
        d->mainLayout->addWidget(statusBar, 2, 0, 1, 1, Qt::AlignBottom);
    }
}

void QPUIWindow::initilizeUI()
{
    Q_D(QPUIWindow);
    if(d->mainLayout)
    {
//        if(d->mainSplitter)
//        {
//            d->mainLayout->addWidget(d->mainSplitter, 1, 0, 1, 1, Qt::AlignCenter);
//        }
        setLayout(d->mainLayout);
    }
}



void QPUIWindowPrivate::init()
{
    mainLayout = new QGridLayout(q_ptr);
    mainLayout->setMargin(0);
    mainLayout->setSpacing(0);
    mainSplitter = new QSplitter(q_ptr);
}
