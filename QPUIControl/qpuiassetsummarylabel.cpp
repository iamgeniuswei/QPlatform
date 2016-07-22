#include "qpuiassetsummarylabel.h"
#include "private/qpuiassetsummarylabel_p.h"
#include <QLabel>
#include <QGridLayout>
QPUIAssetSummaryLabel::QPUIAssetSummaryLabel(QWidget *parent) : QPUIView(new QPUIAssetSummaryLabelPrivate(this), parent)
{
    setObjectName("assetSummary");
    Q_D(QPUIAssetSummaryLabel);
    if(d)
        d->init();
    initilizeUI();
    setAttribute(Qt::WA_TranslucentBackground);


}

void QPUIAssetSummaryLabel::initilizeUI()
{
    Q_D(QPUIAssetSummaryLabel);
    if(d)
    {
        d->mainLayout->setColumnMinimumWidth(0, 10);
        d->mainLayout->setColumnMinimumWidth(2,10);
        d->mainLayout->setColumnMinimumWidth(4,10);
        d->mainLayout->setColumnMinimumWidth(6, 10);
        addWidget(d->assetName, 0, 1, 1, 1);
        addWidget(d->assetType, 1, 1, 1, 1);
        addWidget(d->assetAttr1, 0, 3, 1, 1);
        addWidget(d->assetAttr2, 0, 5, 1, 1);
        addWidget(d->assetAttr3, 1, 3, 1, 1);
        addWidget(d->assetAttr4, 1, 5, 1, 1);
    }
    setMinimumSize(300,80);
    QPUIView::initilizeUI();
}

void QPUIAssetSummaryLabel::setAssetName(const QString &name)
{
    Q_D(QPUIAssetSummaryLabel);
    if(d && d->assetName)
    {
        d->strName = name;
        d->assetName->setText(name);
    }
}

void QPUIAssetSummaryLabel::setAssetType(const QString &type)
{
    Q_D(QPUIAssetSummaryLabel);
    if(d && d->assetType)
    {
        d->strType = type;
        d->assetType->setText(type);
    }
}

void QPUIAssetSummaryLabel::setAssetAttr1(const QString &value)
{
    Q_D(QPUIAssetSummaryLabel);
    if(d && d->assetAttr1)
    {
        d->strAttr1 = value;
        d->assetAttr1->setText(value);
    }
}

void QPUIAssetSummaryLabel::setAssetAttr2(const QString &value)
{
    Q_D(QPUIAssetSummaryLabel);
    if(d && d->assetAttr2)
    {
        d->strAttr2 = value;
        d->assetAttr2->setText(value);
    }
}

void QPUIAssetSummaryLabel::setAssetAttr3(const QString &value)
{
    Q_D(QPUIAssetSummaryLabel);
    if(d && d->assetAttr3)
    {
        d->strAttr3 = value;
        d->assetAttr3->setText(value);
    }
}

void QPUIAssetSummaryLabel::setAssetAttr4(const QString &value)
{
    Q_D(QPUIAssetSummaryLabel);
    if(d && d->assetAttr4)
    {
        d->strAttr4 = value;
        d->assetAttr4->setText(value);
    }
}



void QPUIAssetSummaryLabelPrivate::init()
{
    assetType = new (std::nothrow) QLabel(q_ptr);
    assetType->setObjectName("assetType");
    assetName = new (std::nothrow) QLabel(q_ptr);
    assetName->setObjectName("assetName");
    assetAttr1 = new (std::nothrow) QLabel(q_ptr);
    assetAttr1->setObjectName("assetAttr");
    assetAttr2 = new (std::nothrow) QLabel(q_ptr);
    assetAttr2->setObjectName("assetAttr");
    assetAttr3 = new (std::nothrow) QLabel(q_ptr);
    assetAttr3->setObjectName("assetAttr");
    assetAttr4 = new (std::nothrow) QLabel(q_ptr);
    assetAttr4->setObjectName("assetAttr");
//    separator = new (std::nothrow) QLabel(q_ptr);
}
