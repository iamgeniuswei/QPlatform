#include "qprangeroomview.h"
#include <QGraphicsScene>
#include <QSvgRenderer>
#include "qptopologynode.h"
#include "qplinkelement.h"
#include "qpnodeattribute.h"
#include "qpnodeattribute.h"
#include <QLabel>
#include "qpuipopupwindow.h"
#include "qpnode.h"
#include "qpcabinetnode.h"
#include "qpswitchnode.h"
#include "qprouternode.h"
#include "qpuiassetsummarylabel.h"
#include <QPushButton>
#include <QDebug>
#include <QVector>
#include "qprangeroomserialize.h"
#include "qprangeroomxmlparser.h"
QPRangeRoomView::QPRangeRoomView(QWidget *parent) : QGraphicsView(parent),scene(nullptr)
{
    vector = new (std::nothrow) QVector<QPCabinetNode*>;
    setWindowState(Qt::WindowFullScreen);
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,1680,1050);
    svgRender = new QSvgRenderer(this);
    svgRender->load(QLatin1String("D:/icon/0530.svg"));
    initilizeScene();
    setScene(scene);
    QPushButton *btn = new QPushButton(this);
    connect(btn, SIGNAL(clicked(bool)), this, SLOT(btnClicked()));




}

void QPRangeRoomView::initilizeScene()
{
    QPRangeRoomDeserialize *parser = new QPRangeRoomDeserialize;
    parser->deSerialize();
    QVector<QPCabinetNode*> *vecotr = parser->getVector();
    QVectorIterator<QPCabinetNode*> iterator(*vecotr);
    qDebug() << iterator.hasNext();
    while (iterator.hasNext()) {
        QPCabinetNode *node = iterator.next();
        if(node)
        {
            QPTopologyNode *topoNode = new QPTopologyNode;
            topoNode->setNodeText(node->getNodeName());
            topoNode->setSharedRenderer(svgRender);
            topoNode->setElementId(QLatin1String("XMLID_29_"));
            topoNode->setPos(node->getDeployPoint());
            scene->addItem(topoNode);
            nodeAttrHash.insert(topoNode, node);
            connect(topoNode, SIGNAL(mouseDoubleClickSignal(QPTopologyNode*)), this, SLOT(itemMouseDoubleClicked(QPTopologyNode*)));
        }
    }
}

void QPRangeRoomView::itemMouseDoubleClicked(QPTopologyNode *node)
{
    QPUIPopupWindow *nodeAttrDlg = new (std::nothrow) QPUIPopupWindow;
    QPNode *nodeAttr = nodeAttrHash.value(node);
    if(nodeAttrDlg && nodeAttr)
    {
        QLabel *logo = new QLabel(nodeAttrDlg);
        logo->setObjectName("nodeTL");
        nodeAttrDlg->setTitleLogo(logo);

        QPUIAssetSummaryLabel *text = new QPUIAssetSummaryLabel(nodeAttrDlg);
        text->setAssetName(nodeAttr->getNodeName());
        text->setAssetType("Cabinet");
        nodeAttrDlg->setTitleWidget(text);
//        for(int i = 0; i < 2; i++)
//        {
//            QPUIAssetSummaryLabel *deviceSummary = new QPUIAssetSummaryLabel(nodeAttrDlg);
//            QPNode *device = nodeAttr->getChild(i);
//            deviceSummary->setAssetName(device->getNodeName());
//            deviceSummary->setAssetType("Switch");
//            nodeAttrDlg->addContentArea(deviceSummary);
//        }


        nodeAttrDlg->initilizeUI();
        nodeAttrDlg->show();
    }
    //    return nullptr;
}

void QPRangeRoomView::btnClicked()
{
    QList<QGraphicsItem*> list = scene->items();
    for(int i = 0; i<list.size(); i++)
    {
        QGraphicsItem *item = list.at(i);
        QPTopologyNode *node = (QPTopologyNode*)item;
//        qDebug() << item->pos();

        QPNode *cabnode = nodeAttrHash.value(node);
        QPCabinetNode *cabinet = (QPCabinetNode*)cabnode;
        qDebug() << node->scenePos();
        cabinet->setDeployPoint(node->scenePos());
        vector->append(cabinet);
    }

    QPRangeRoomSerialize *serilize = new QPRangeRoomSerialize;
    serilize->setVector(vector);
    serilize->serialize();
    delete serilize;
}

