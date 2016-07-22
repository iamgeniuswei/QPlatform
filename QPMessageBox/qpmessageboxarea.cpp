#include "qpmessageboxarea.h"
#include "private/qpmessageboxarea_p.h"
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QStyle>
QPMessageBoxArea::QPMessageBoxArea(QWidget *parent) : QPUIWidget(parent),
    d_ptr(new QPMessageBoxAreaPrivate(this))
{
    Q_D(QPMessageBoxArea);
    d->init();
    setMinimumHeight(100);
    initilizeUI();
}

void QPMessageBoxArea::initilizeUI()
{
    Q_D(QPMessageBoxArea);
    d->initInformativeLabel();
    if(d->mainLayout)
    {
        d->mainLayout->addWidget(d->iconLabel, 1, 1, 1, 1, Qt::AlignVCenter|Qt::AlignHCenter);
        d->mainLayout->addWidget(d->informativeLabel, 1, 2, 1, 4);
        d->mainLayout->addWidget(d->okBtn, 2, 4, 1, 1);
        d->mainLayout->addWidget(d->cancelBtn, 2, 5, 1, 1);
    }
}

void QPMessageBoxArea::setInformativeText(const QString &text)
{
    Q_D(QPMessageBoxArea);
    if(d->informativeLabel)
    {

        d->informativeLabel->setMaximumWidth(100);
//        d->informativeLabel->setGeometry(QRect(328, 240, 100, 27*4));
        d->informativeLabel->setWordWrap(true);
//        d->informativeLabel->setAlignment(Qt::AlignTop);
//        d->mainLayout->setSizeConstraint(QLayout::SetFixedSize);
        d->informativeLabel->setText(text);
        update();
    }
}

void QPMessageBoxArea::setIcon(QPMessageBoxArea::Icon type)
{
    Q_D(QPMessageBoxArea);
    if(d->iconLabel)
    {
        switch (type) {
        case Question:
            d->iconLabel->setPixmap(d->iconLabel->style()->standardPixmap(QStyle::SP_MessageBoxQuestion));
            break;
        case Information:
            d->iconLabel->setPixmap(d->iconLabel->style()->standardPixmap(QStyle::SP_MessageBoxInformation));
            break;
        case Critical:
            d->iconLabel->setPixmap(d->iconLabel->style()->standardPixmap(QStyle::SP_MessageBoxCritical));
            break;
        case Warning:
            d->iconLabel->setPixmap(d->iconLabel->style()->standardPixmap(QStyle::SP_MessageBoxWarning));
            break;
        default:
            break;
        }
    }
}


void QPMessageBoxAreaPrivate::init()
{
    mainLayout = new QGridLayout(q_ptr);
    iconLabel = new QLabel(q_ptr);
    informativeLabel = new QLabel(q_ptr);
    okBtn = new QPushButton(q_ptr);
    cancelBtn = new QPushButton(q_ptr);
}


void QPMessageBoxAreaPrivate::initLayout()
{
    if(mainLayout)
    {
        mainLayout->setMargin(1);
        mainLayout->setColumnMinimumWidth(0, 10);
        mainLayout->setColumnMinimumWidth(1, 10);
        mainLayout->setColumnMinimumWidth(2, 50);
        mainLayout->setColumnStretch(2, 1);
        mainLayout->setColumnMinimumWidth(3, 30);
    }
}

void QPMessageBoxAreaPrivate::initIconLabel()
{
    if(iconLabel)
    {
        iconLabel->setObjectName("msgBoxIcon");
    }
}

void QPMessageBoxAreaPrivate::initInformativeLabel()
{
    if(informativeLabel)
    {
        informativeLabel->setObjectName("msgBoxContent");
//        informativeLabel->setMaximumWidth(50);


    }
}

void QPMessageBoxAreaPrivate::initOkBtn()
{

}

void QPMessageBoxAreaPrivate::initCancelBtn()
{

}
