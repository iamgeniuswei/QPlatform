#include "qpsiptopologyview.h"
#include <QSvgRenderer>
#include <QGraphicsScene>
#include "qptopologynode.h"
#include "qplinkelement.h"
QPSIPTopologyView::QPSIPTopologyView(QWidget *parent) : QGraphicsView(parent)
{

    scene = new QGraphicsScene(this);
//    scene->setSceneRect(0,0,1680,1050);
    svgRender = new QSvgRenderer(this);
    svgRender->load(QLatin1String("D:/icon/test.svg"));
    initilizeScene();
    setScene(scene);
}

void QPSIPTopologyView::initilizeScene()
{

    QPen pen;
    pen.setColor(QColor(0,201,249));
    pen.setWidth(3);

    QPTopologyNode *router = new QPTopologyNode;
    router->setNodeText("Router");
    router->setSharedRenderer(svgRender);
    router->setElementId(QLatin1String("group2-1"));
    router->setPos(800,500);

    QPTopologyNode *switch1 = new QPTopologyNode;
    switch1->setNodeText("switch1");
    switch1->setSharedRenderer(svgRender);
    switch1->setElementId(QLatin1String("group7-12"));
    switch1->setPos(600,500);


    QPLinkElement *link1 = new QPLinkElement;
    link1->setPen(pen);
    link1->setEndPoint(router, switch1);



    QPTopologyNode *sipServer1 = new QPTopologyNode;
    sipServer1->setNodeText("sipServer1");
    sipServer1->setSharedRenderer(svgRender);
    sipServer1->setElementId(QLatin1String("group12-23"));
    sipServer1->setPos(400,500);
    QPLinkElement *link2 = new QPLinkElement;
    link2->setPen(pen);
    link2->setEndPoint(switch1, sipServer1);

    QPTopologyNode *xmppServer1 = new QPTopologyNode;
    xmppServer1->setNodeText("XMPPServer");
    xmppServer1->setSharedRenderer(svgRender);
    xmppServer1->setElementId(QLatin1String("group12-23"));
    xmppServer1->setPos(400,800);
    QPLinkElement *link9 = new QPLinkElement;
    link9->setPen(pen);
    link9->setEndPoint(switch1, xmppServer1);

    QPTopologyNode *imUser1 = new QPTopologyNode;
    imUser1->setNodeText("IMUser1");
    imUser1->setSharedRenderer(svgRender);
    imUser1->setElementId(QLatin1String("group30-59"));
    imUser1->setPos(200,1000);
    QPLinkElement *link13 = new QPLinkElement;
    link13->setPen(pen);
    link13->setEndPoint(xmppServer1, imUser1);

    QPTopologyNode *imUser2 = new QPTopologyNode;
    imUser2->setNodeText("IMUser2");
    imUser2->setSharedRenderer(svgRender);
    imUser2->setElementId(QLatin1String("group30-59"));
    imUser2->setPos(600,1000);
    QPLinkElement *link14 = new QPLinkElement;
    link14->setPen(pen);
    link14->setEndPoint(xmppServer1, imUser2);



    QPTopologyNode *sipphone1 = new QPTopologyNode;
    sipphone1->setNodeText("sipphone1");
    sipphone1->setSharedRenderer(svgRender);
    sipphone1->setElementId(QLatin1String("group16-31"));
    sipphone1->setPos(200,400);

    QPLinkElement *link3 = new QPLinkElement;
    link3->setPen(pen);
    link3->setEndPoint(sipServer1, sipphone1);

    QPTopologyNode *sipphone2 = new QPTopologyNode;
    sipphone2->setNodeText("sipphone2");
    sipphone2->setSharedRenderer(svgRender);
    sipphone2->setElementId(QLatin1String("group16-31"));
    sipphone2->setPos(200,600);
    QPLinkElement *link4 = new QPLinkElement;
    link4->setPen(pen);
    link4->setEndPoint(sipServer1, sipphone2);

    QPTopologyNode *switch2 = new QPTopologyNode;
    switch2->setNodeText("switch2");
    switch2->setSharedRenderer(svgRender);
    switch2->setElementId(QLatin1String("group7-12"));
    switch2->setPos(1000,500);
    QPLinkElement *link5 = new QPLinkElement;
    link5->setPen(pen);
    link5->setEndPoint(router, switch2);



    QPTopologyNode *sipServer2 = new QPTopologyNode;
    sipServer2->setNodeText("sipServer2");
    sipServer2->setSharedRenderer(svgRender);
    sipServer2->setElementId(QLatin1String("group12-23"));
    sipServer2->setPos(1200,500);
    QPLinkElement *link6 = new QPLinkElement;
    link6->setPen(pen);
    link6->setEndPoint(switch2, sipServer2);

    QPTopologyNode *wirelessAP = new QPTopologyNode;
    wirelessAP->setNodeText("wirelessAP");
    wirelessAP->setSharedRenderer(svgRender);
    wirelessAP->setElementId(QLatin1String("group26-51"));
    wirelessAP->setPos(1200,800);
    QPLinkElement *link10 = new QPLinkElement;
    link10->setPen(pen);
    link10->setEndPoint(switch2, wirelessAP);

    QPTopologyNode *phone1 = new QPTopologyNode;
    phone1->setNodeText("iphone");
    phone1->setSharedRenderer(svgRender);
    phone1->setElementId(QLatin1String("group21-41"));
    phone1->setPos(1000,1000);
    QPLinkElement *link11 = new QPLinkElement;
    link11->setPen(pen);
    link11->setEndPoint(wirelessAP, phone1);

    QPTopologyNode *phone2 = new QPTopologyNode;
    phone2->setNodeText("andriod");
    phone2->setSharedRenderer(svgRender);
    phone2->setElementId(QLatin1String("group21-41"));
    phone2->setPos(1400,1000);
    QPLinkElement *link12 = new QPLinkElement;
    link12->setPen(pen);
    link12->setEndPoint(wirelessAP, phone2);



    QPTopologyNode *sipphone3 = new QPTopologyNode;
    sipphone3->setNodeText("sipphone3");
    sipphone3->setSharedRenderer(svgRender);
    sipphone3->setElementId(QLatin1String("group16-31"));
    sipphone3->setPos(1400,400);
    QPLinkElement *link7 = new QPLinkElement;
    link7->setPen(pen);
    link7->setEndPoint(sipServer2, sipphone3);


    QPTopologyNode *sipphone4 = new QPTopologyNode;
    sipphone4->setNodeText("sipphone4");
    sipphone4->setSharedRenderer(svgRender);
    sipphone4->setElementId(QLatin1String("group16-31"));
    sipphone4->setPos(1400,600);

    QPLinkElement *link8 = new QPLinkElement;
    link8->setPen(pen);
    link8->setEndPoint(sipServer2, sipphone4);

    scene->addItem(link1);
    scene->addItem(link2);
    scene->addItem(link3);
    scene->addItem(link4);
    scene->addItem(link5);
    scene->addItem(link6);
    scene->addItem(link7);
    scene->addItem(link8);
    scene->addItem(link9);
    scene->addItem(link10);
    scene->addItem(link11);
    scene->addItem(link12);
    scene->addItem(link13);
    scene->addItem(link14);

    scene->addItem(router);
    scene->addItem(switch1);
    scene->addItem(switch2);
    scene->addItem(sipServer1);
    scene->addItem(xmppServer1);
    scene->addItem(imUser1);
    scene->addItem(imUser2);
    scene->addItem(sipServer2);
    scene->addItem(wirelessAP);
    scene->addItem(phone1);
    scene->addItem(phone2);
    scene->addItem(sipphone1);
    scene->addItem(sipphone2);
    scene->addItem(sipphone3);
    scene->addItem(sipphone4);


}

