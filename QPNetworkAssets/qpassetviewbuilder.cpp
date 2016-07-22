#include "qpassetviewbuilder.h"
#include "qpuiview.h"
#include "qpuistaticallabelbuilder.h"
#include "qpassetdetailbuilder.h"
#include <QLabel>

#include <QTableView>
#include "qpuipagecontrol.h"
#include <QGridLayout>
#include "qpuistaticallabel.h"
QPAssetViewBuilder::QPAssetViewBuilder(QObject *parent) : QPUIViewBuilder(parent),assetView(nullptr)
{

}

void QPAssetViewBuilder::buildView()
{
    QPUIView *uiView = new (std::nothrow) QPUIView;
    if(uiView)
    {
//        uiView->setFixedSize(1680, 1050);
        uiView->setObjectName("assetView");
        uiView->getLayout()->setColumnMinimumWidth(0, 10);
        QLabel *assetSumary = new (std::nothrow) QLabel(uiView);
        assetSumary->setObjectName("assetSummary");
        uiView->addWidget(assetSumary, 0, 1, 1, 7);

        QPUIStaticalLabel *label = new QPUIStaticalLabel(uiView);
        label->setObjectName("staticalLabel");
        uiView->addWidget(label, 1, 1, 1, 1);

        QPUIStaticalLabel *label1 = new QPUIStaticalLabel(uiView);
        label1->setObjectName("staticalLabel");
        uiView->addWidget(label1, 1, 2, 1, 1);
        QPUIStaticalLabel *label2 = new QPUIStaticalLabel(uiView);
        label2->setObjectName("staticalLabel");
        uiView->addWidget(label2, 1, 3, 1, 1);

        QPUIStaticalLabel *label3 = new QPUIStaticalLabel(uiView);
        label3->setObjectName("staticalLabelTest");
        uiView->addWidget(label3, 1, 4, 1, 1);
        label3->setStaticalValue(900);
//        for(int i = 0; i < 7; i++)
//        {
//            QPUIStaticalLabelBuilder *routerLabelB = new QPUIStaticalLabelBuilder;
//            routerLabelB->buildView();
//            QPUIView *routerLabel = routerLabelB->getUIView();
//            uiView->addWidget(routerLabel, 1, i, 1, 1);
//            delete routerLabelB;
//            routerLabelB = nullptr;
//        }

        QLabel *assetDetail = new (std::nothrow) QLabel(uiView);
        assetDetail->setObjectName("assetSummary");
        uiView->addWidget(assetDetail, 3, 1, 1, 7);

        QPUIPageControl *pageControl = new QPUIPageControl(uiView);
        uiView->addWidget(pageControl, 4, 1, 1, 5);
        pageControl->setTableName("PATaskInfo");
        pageControl->queryPageData();
        uiView->getLayout()->setRowStretch(5,1);

        QPAssetDetailBuilder *detailBuilder = new QPAssetDetailBuilder;
        detailBuilder->buildView();
        QPUIView *detailView = detailBuilder->getUIView();
        delete detailBuilder;
        uiView->addWidget(detailView, 4, 6, 1, 2);

    }
    assetView = uiView;
}

QPUIView *QPAssetViewBuilder::getUIView()
{
    if(assetView)
        assetView->initilizeUI();
    return assetView;
}

