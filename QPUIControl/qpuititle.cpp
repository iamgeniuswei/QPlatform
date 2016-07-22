#include "qpuititle.h"
#include "private/qpuititle_p.h"
#include <QGridLayout>
#include <QMouseEvent>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
QPUITitle::QPUITitle(QWidget *parent) : QPUIWidget(parent),d_ptr(new QPUITitlePrivate(this))
{
    Q_D(QPUITitle);
    d->init();
}

void QPUITitle::addTitleLogo(QLabel *logo)
{
    Q_D(QPUITitle);
    if(logo && d->mainLayout)
    {
        d->mainLayout->addWidget(logo, 0, 1, 3, 1, Qt::AlignVCenter);
    }
}

void QPUITitle::addTitleText(QWidget *text)
{
    Q_D(QPUITitle);
    if(text && d->mainLayout)
    {
        d->mainLayout->addWidget(text, 0, 2, 3, 1, Qt::AlignVCenter);
    }
}

void QPUITitle::addSubTitleText(QLabel *text)
{
    Q_D(QPUITitle);
    if(text && d->mainLayout)
    {
        d->mainLayout->addWidget(text, 2, 3, 1, 1, Qt::AlignTop);
    }
}

void QPUITitle::addSysBtn(QPushButton *sysBtn)
{
    Q_D(QPUITitle);
    if(sysBtn)
    {
        if(d->sysBtnLayout)
        {
            d->sysBtnLayout->addWidget(sysBtn);
        }
        else
        {
            d->sysBtnLayout = new QHBoxLayout;
            if(d->sysBtnLayout)
                d->sysBtnLayout->addWidget(sysBtn);
        }
    }
}

void QPUITitle::addUserBtn(QWidget *userBtn)
{
    Q_D(QPUITitle);
    if(userBtn)
    {
        if(d->userBtnLayout)
            {
            d->userBtnLayout->addWidget(userBtn, 0, Qt::AlignVCenter|Qt::AlignCenter);
        }
        else
            {
            d->userBtnLayout = new QHBoxLayout;
            if(d->userBtnLayout)
            {
                d->userBtnLayout->setMargin(0);
                d->userBtnLayout->addWidget(userBtn, 0, Qt::AlignVCenter|Qt::AlignCenter);
            }
        }
    }
}

void QPUITitle::setParent(QWidget *parent)
{
    Q_D(QPUITitle);
    d->parentWindow = parent;
    //TODO: setParent
//    QWidget::setParent(parent);
}

void QPUITitle::initilizeUI()
{
    Q_D(QPUITitle);
    if(d->mainLayout)
    {
        if(d->userBtnLayout)
        {
            d->mainLayout->addLayout(d->userBtnLayout, 1, 5, 2, 1, Qt::AlignBottom);
        }
        if(d->sysBtnLayout)
        {
            d->mainLayout->addLayout(d->sysBtnLayout, 0, 7, 1, 1);
        }
        setLayout(d->mainLayout);
    }
}

void QPUITitle::mousePressEvent(QMouseEvent *event)
{
    Q_D(QPUITitle);
    if(event->button() == Qt::LeftButton)
    {
        d->mousePress = true;
    }
    d->moveDistance = event->globalPos() - pos();
}

void QPUITitle::mouseMoveEvent(QMouseEvent *event)
{
    Q_D(QPUITitle);
    if(d->mousePress  && d->windowMove)
    {
        QPoint movePos = event->globalPos();
        if(d->parentWindow)
        {
            d->parentWindow->move(d->parentWindow->pos() + movePos - d->moveDistance);
            d->moveDistance = movePos;
        }
        else
            move(movePos - d->moveDistance);
    }
}

void QPUITitle::mouseReleaseEvent(QMouseEvent *)
{
    Q_D(QPUITitle);
    d->mousePress = false;
}



void QPUITitlePrivate::init()
{
    mainLayout = new QGridLayout(q_ptr);
    if(mainLayout)
    {
        mainLayout->setMargin(1);
        mainLayout->setColumnMinimumWidth(0, 10);
        mainLayout->setColumnMinimumWidth(1, 10);
        mainLayout->setColumnMinimumWidth(2, 50);
        mainLayout->setColumnStretch(3, 1);
        mainLayout->setColumnMinimumWidth(3, 30);
    }
}
