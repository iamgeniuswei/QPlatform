#include "qpmainwindowbuilder.h"
#include "private/qpmainwindowbuilder_p.h"
#include "qpuiwindow.h"
#include "qpuititle.h"
#include "qpmaintitlebuilder.h"
#include "qpuititledirector.h"
#include "qpuistatusbar.h"
#include <QTabWidget>
#include <QTextEdit>
#include "qpuiview.h"
#include "qpassetviewbuilder.h"
#include "qpsiptopologyview.h"
#include "sipfuzzyview.h"
QPMainWindowBuilder::QPMainWindowBuilder(QObject *parent) : QPUIWindowBuilder(parent),
    d_ptr(new QPMainWindowBuilderPrivate)
{
    Q_D(QPMainWindowBuilder);
    d->init();
}

void QPMainWindowBuilder::buildTitle()
{
    Q_D(QPMainWindowBuilder);
    QPUITitleBuilder *builder = new QPMainTitleBuilder;
    QPUITitleDirector *director = new QPUITitleDirector;
    director->buildTitle(builder);
    QPUITitle *mainTitle = builder->getTitleInstance();
    if(mainTitle)
    {
        mainTitle->setParent(d->mainWindow);
        d->mainWindow->addTitle(mainTitle);
    }
}

void QPMainWindowBuilder::buildNavigationBar()
{

}

void QPMainWindowBuilder::buildContentArea()
{
    Q_D(QPMainWindowBuilder);
    QTabWidget *tabWidget = new QTabWidget(d->mainWindow);
    if(tabWidget)
        {

//        QPAssetViewBuilder *builder = new QPAssetViewBuilder;
//        builder->buildView();
//        QPUIView *w = builder->getUIView();
    QPSIPTopologyView *sipView = new QPSIPTopologyView(d->mainWindow);
    d->mainWindow->addContentArea(tabWidget);

    SIPFuzzyView *fuzzyView = new SIPFuzzyView(d->mainWindow);
    tabWidget->addTab(sipView, "SIP VIEW");
    tabWidget->addTab(fuzzyView, "Fuzzy View");

//        d->mainWindow->addContentArea(w);
//        tabWidget->addTab(w, "Asset View");
//        tabWidget->addTab(new QTextEdit("tab 1"), "tab1");
//        tabWidget->addTab(new QTextEdit("tab2"), "tab2");

    }

}

void QPMainWindowBuilder::buildStatusBar()
{
    Q_D(QPMainWindowBuilder);
    QPUIStatusBar *statusBar = new QPUIStatusBar(d->mainWindow);
    if(statusBar)
    {
        d->mainWindow->addStatusBar(statusBar);
    }
}

QPUIWindow *QPMainWindowBuilder::getWindowInstance()
{
    Q_D(QPMainWindowBuilder);
    if(d->mainWindow)
    {
        d->mainWindow->initilizeUI();
        d->mainWindow->setFixedSize(1680, 1050);
    }
    return d->mainWindow;
}



void QPMainWindowBuilderPrivate::init()
{
    mainWindow = new QPUIWindow;
}
