#include "widget.h"
#include <QApplication>
#include <QTranslator>
#include <QFile>
#include "qpuiwidget.h"
#include <QLabel>
#include <QPushButton>

//Test File
#include "qpuititle.h"
#include "qpmaintitlebuilder.h"
#include "qpuititledirector.h"

#include "qpmessagebox.h"
#include "qpuistatusbar.h"
#include "qpuiwindow.h"
#include "qpmainwindowbuilder.h"
#include "qpuiwindowdirector.h"

#include <QComboBox>

#include <QLineEdit>
#include "qprealtimechart.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include "qptopologynode.h"
#include "qplinkelement.h"
#include <QSvgRenderer>
#include "qptopologynode.h"


#include "qpuistaticallabelbuilder.h"
#include "qpuiview.h"

#include "qpassetviewbuilder.h"
#include <QLineEdit>
#include "qpuipagecontroltoolbar.h"

#include "qperrorinfoqueue.h"

#include "qpuipagecontrol.h"

#include "qpsqlconnection.h"
#include "qprivatesqlhelper.h"
#include "qpuistaticallabel.h"
#include "slidingwindow.h"

#include "qpuipopupwindow.h"
#include "qpuiassetsummarylabel.h"
#include "qpnetworktopology.h"


#include "qprangeroomview.h"


#include "form.h"

#include "qpsiptopologyview.h"
#include "sipfuzzyview.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    QPrivateSqlHelper::createObject();
//    QPrivateSqlHelper::createModelObject();
//    QPSqlConnection *conn = new QPSqlConnection;
////    qDebug() << conn->ConnectionToDBByName("",\
////                               "TaskDB",\
////                               "192.168.1.201",\
////                               1521,\
////                               "ORCL",\
////                               "ronaldo",\
////                               "qhtf20150622");
//    qDebug() << conn->ConnectionToDBByDefault("QOCI",\
//                               "192.168.1.226",\
//                               1521,\
//                               "ORCL",\
//                               "XYFX2",\
//                               "123456");
//    delete conn;




    QFile qss(":/qss/version1");
    qss.open(QFile::ReadOnly);
    qApp->setStyleSheet(qss.readAll());
    qss.close();


    const QString langPath = ":/lang/lang_zh";
    QTranslator translator;
    translator.load(langPath);
    a.installTranslator(&translator);

//    QPUITitleBuilder *builder = new QPMainTitleBuilder;
//    QPUITitleDirector *director = new QPUITitleDirector;
//    director->buildTitle(builder);
//    QPUITitle *title = builder->getTitleInstance();
//    title->show();

//    QPMessageBox *w = new QPMessageBox;
//    w->setInformativeText("adfafafasfasfasdfasdafafasfasfasdfasfafadsfasfasfasdfaaaaaaaaaaaaaaaaaaaaaaaaaaaab");
//    w->show();
//    QPUIStatusBar *w = new QPUIStatusBar;
//    w->show();

    QPUIWindowBuilder *builder = new QPMainWindowBuilder;
    QPUIWindowDirector *director = new QPUIWindowDirector;
    director->buildWindow(builder);
    QPUIWindow  *mainWindow = builder->getWindowInstance();
    mainWindow->show();

//    QComboBox *w = new QComboBox;
//    w->addItem("adfadfa");
//    QLineEdit *w = new QLineEdit;
//    w->show();
//    QPRealtimeChart *w = new QPRealtimeChart;
//    w->show();

//    QPUIWidget *w = new QPUIWidget;
//    QGraphicsView *w = new QGraphicsView;
//    QGraphicsScene *scene = new QGraphicsScene;
//    w->setScene(scene);

//    QSvgRenderer *renderer = new QSvgRenderer(QLatin1String("D:/icon/0519.svg"));
//    QPDeviceElement *black = new QPDeviceElement();
////    black->setFlags(QGraphicsItem::ItemIsMovable|QGraphicsItem::ItemIsSelectable);
//    QPDeviceElement *red   = new QPDeviceElement();

//    black->setSharedRenderer(renderer);
//    black->setElementId(QLatin1String("CoreRouter_Normal"));
//    black->setToolTip("router");
//    black->setPos(100, 100);


//    red->setSharedRenderer(renderer);
//    red->setElementId(QLatin1String("CoreSwitch_Normal"));
////    red->setFlags(QGraphicsItem::ItemIsMovable|QGraphicsItem::ItemIsSelectable);
//    red->setPos(400,400);

//    QPDeviceElement *black1 = new QPDeviceElement();
////    black->setFlags(QGraphicsItem::ItemIsMovable|QGraphicsItem::ItemIsSelectable);
//    QPDeviceElement *red1   = new QPDeviceElement();

//    black1->setSharedRenderer(renderer);
//    black1->setElementId(QLatin1String("CoreRouter_Normal"));
//    black1->setToolTip("router");
//    black1->setPos(200, 200);


//    red1->setSharedRenderer(renderer);
//    red1->setElementId(QLatin1String("CoreSwitch_Normal"));
////    red->setFlags(QGraphicsItem::ItemIsMovable|QGraphicsItem::ItemIsSelectable);
//    red1->setPos(300,300);

//    QPLinkElement *link1 = new QPLinkElement;
//    link1->setEndPoint(black1, red1);


//    QPLinkElement *link = new QPLinkElement;
//    link->setEndPoint(black, red);
//    QPen pen;
//    pen.setColor(QColor(0,201,249));
//    pen.setWidth(3);
//    link->setPen(pen);
//    link1->setPen(pen);
////    link->setLine(100, 100, 300, 300);
//    link->setFlags(QGraphicsItem::ItemIsMovable|QGraphicsItem::ItemIsSelectable);
//    scene->addItem(link);
//    scene->addItem(link1);


//    scene->addItem(black);
//    scene->addItem(red);
//    scene->addItem(black1);
//    scene->addItem(red1);

////    black->setElementId(QLatin1String("CoreRouter_Active"));


////    QPAssetViewBuilder *builder = new QPAssetViewBuilder;
////    builder->buildView();
////    QPUIView *w = builder->getUIView();

////    QLineEdit *w = new QLineEdit;

////    QPUIPageControlToolBar *w = new QPUIPageControlToolBar;
////    QPUIPageControl *w = new QPUIPageControl;

//    w->show();

//    w->updateTotalRecord(100,100);


//    QPUIStaticalLabel *w = new QPUIStaticalLabel;
//    w->setObjectName("staticalLabel");
//    w->show();

    QPErrorInfoQueue *queue = QPErrorInfoQueue::getInstance();

//    w->setStaticalValue(200);

//    Widget *w = new Widget;
//    w->show();

//    SlidingWindow *w = new SlidingWindow;
//    w->show();


//    QPUIPopupWindow *w = new QPUIPopupWindow;
//    QLabel *logo = new QLabel(w);
//    logo->setObjectName("MTlogo");

//    w->setTitleLogo(logo);
////    w->addContentArea(area);
//    w->initilizeUI();
//    w->show();
//    QPUIAssetSummaryLabel *w = new QPUIAssetSummaryLabel;
//    w->setAssetName("Cisco S-400");
//    w->setAssetType("Core Router");
//    w->setAssetAttr1("fsdfafefa");
//    w->setAssetAttr2("2344342342");
//    w->setAssetAttr3("dfafafas");
//    w->setAssetAttr4("ff343UDFHFD");
//    w->show();

//    QGraphicsView *w = new QGraphicsView;
//    QPNetworkTopology *topo = new QPNetworkTopology;
//    w->setScene(topo->sence());
//    w->show();

//    QPRangeRoomView *w = new QPRangeRoomView;
//    w->show();
//    Form *w = new Form;
//    w->show();
//    QPSIPTopologyView *w = new QPSIPTopologyView;
//    w->show();\

//    SIPFuzzyView *w = new SIPFuzzyView;
//    w->show();


    return a.exec();
}
