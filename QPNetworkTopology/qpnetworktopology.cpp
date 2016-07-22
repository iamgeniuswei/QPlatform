#include "qpnetworktopology.h"
#include <QSvgRenderer>
#include <QGraphicsScene>
#include "qptopologynode.h"
#include "qplinkelement.h"
#include "qpnodeattribute.h"
QPNetworkTopology::QPNetworkTopology(QObject *parent):
    scene(nullptr), svgRender(nullptr)
{
    scene = new QGraphicsScene(this);
    svgRender = new QSvgRenderer(this);
    svgRender->load(QLatin1String("D:/icon/0519.svg"));
    initilizeScene();
}

QGraphicsScene *QPNetworkTopology::sence() const
{
    return scene;
}

void QPNetworkTopology::initilizeScene()
{

    QPTopologyNode *black = new QPTopologyNode();
    //    black->setFlags(QGraphicsItem::ItemIsMovable|QGraphicsItem::ItemIsSelectable);
    QPTopologyNode *red   = new QPTopologyNode();

    black->setSharedRenderer(svgRender);
    black->setElementId(QLatin1String("CoreRouter_Normal"));
    black->setToolTip("router");
    black->setPos(100, 100);
    black->getAttribute()->setTypeName("Router");


    red->setSharedRenderer(svgRender);
    red->setElementId(QLatin1String("CoreSwitch_Normal"));
    //    red->setFlags(QGraphicsItem::ItemIsMovable|QGraphicsItem::ItemIsSelectable);
    red->setPos(400,400);
    red->getAttribute()->setTypeName("Switch");

    QPTopologyNode *black1 = new QPTopologyNode();
    //    black->setFlags(QGraphicsItem::ItemIsMovable|QGraphicsItem::ItemIsSelectable);
    QPTopologyNode *red1   = new QPTopologyNode();

    black1->setSharedRenderer(svgRender);
    black1->setElementId(QLatin1String("CoreRouter_Normal"));
    black1->setToolTip("router");
    black1->setPos(200, 200);


    red1->setSharedRenderer(svgRender);
    red1->setElementId(QLatin1String("CoreSwitch_Normal"));
    //    red->setFlags(QGraphicsItem::ItemIsMovable|QGraphicsItem::ItemIsSelectable);
    red1->setPos(300,300);

    QPLinkElement *link1 = new QPLinkElement;
    link1->setEndPoint(black1, red1);


    QPLinkElement *link = new QPLinkElement;
    link->setEndPoint(black, red);
    QPen pen;
    pen.setColor(QColor(0,201,249));
    pen.setWidth(3);
    link->setPen(pen);
    link1->setPen(pen);
    //    link->setLine(100, 100, 300, 300);
    link->setFlags(QGraphicsItem::ItemIsMovable|QGraphicsItem::ItemIsSelectable);
    scene->addItem(link);
    scene->addItem(link1);


    scene->addItem(black);
    scene->addItem(red);
    scene->addItem(black1);
    scene->addItem(red1);
}
