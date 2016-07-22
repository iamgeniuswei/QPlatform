#include "qpuistaticallabelbuilder.h"
#include "qpuiview.h"
#include <QLabel>
QPUIStaticalLabelBuilder::QPUIStaticalLabelBuilder(QObject *parent) : QPUIViewBuilder(parent),staticalLabel(new (std::nothrow) QPUIView)
{

}

void QPUIStaticalLabelBuilder::buildView()
{
    if(staticalLabel)
    {
        QLabel *staticalType = new (std::nothrow) QLabel(staticalLabel);
        staticalType->setObjectName("staticalType");
        QLabel *staticalData = new (std::nothrow) QLabel(staticalLabel);
        staticalData->setObjectName("staticalData");
        staticalLabel->addWidget(staticalType, 0,0,1,1);
        staticalLabel->addWidget(staticalData, 1,0,1,1);
        staticalLabel->setObjectName("staticalLabel");
        staticalLabel->setFixedSize(100,80);
    }
}

QPUIView *QPUIStaticalLabelBuilder::getUIView()
{
    if(staticalLabel)
    {
        staticalLabel->initilizeUI();
    }
    return staticalLabel;
}

