#include "qpassetdetailbuilder.h"
#include "qpuiview.h"
#include <QLabel>
#include <QGridLayout>
QPAssetDetailBuilder::QPAssetDetailBuilder(QObject *parent) : QPUIViewBuilder(parent), detailView(nullptr)
{

}

void QPAssetDetailBuilder::buildView()
{
    QPUIView *view = new (std::nothrow) QPUIView;
    if(view)
    {
        QLabel *headerLabel = new QLabel(view);
        headerLabel->setObjectName("headerLabel");
        view->addWidget(headerLabel, 0, 0, 1, 2);
        view->getLayout()->setRowStretch(1, 1);

    }
    detailView = view;
}

QPUIView *QPAssetDetailBuilder::getUIView()
{
    if(detailView)
        detailView->initilizeUI();
    return detailView;
}

