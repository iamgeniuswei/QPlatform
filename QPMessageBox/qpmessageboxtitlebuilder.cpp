#include "qpmessageboxtitlebuilder.h"
#include "private/qpmessageboxtitlebuilder_p.h"
#include <QLabel>
#include <QPushButton>
#include "qpuititle.h"
#include <QStyle>
QPMessageBoxTitleBuilder::QPMessageBoxTitleBuilder(QObject *parent) : QPUITitleBuilder(parent),
    d_ptr(new QPMessageBoxTitleBuilderPrivate)
{
    Q_D(QPMessageBoxTitleBuilder);
    d->init();
}

void QPMessageBoxTitleBuilder::buildLogo()
{
    Q_D(QPMessageBoxTitleBuilder);
    QLabel *logo = nullptr;
    logo = new QLabel(d->mainTitle);
    if(logo && d->mainTitle)
    {
        logo->setObjectName("msgLogo");
        d->mainTitle->addTitleLogo(logo);
    }
}

void QPMessageBoxTitleBuilder::buildText()
{
    Q_D(QPMessageBoxTitleBuilder);
    QLabel *text = nullptr;
    text = new QLabel(d->mainTitle);
    if(text && d->mainTitle)
    {
        text->setObjectName("msgText");
        d->mainTitle->addTitleText(text);
    }
}

void QPMessageBoxTitleBuilder::buildSysBtn()
{
    Q_D(QPMessageBoxTitleBuilder);
    QPushButton *closeBtn = nullptr;
    closeBtn = new QPushButton(d->mainTitle);
    if(closeBtn && d->mainTitle)
    {
        closeBtn->setObjectName("closeBtn");
        closeBtn->setIcon(closeBtn->style()->standardIcon(QStyle::SP_DialogCloseButton));
        d->mainTitle->addSysBtn(closeBtn);
    }
}

QPUITitle *QPMessageBoxTitleBuilder::getTitleInstance()
{
    Q_D(QPMessageBoxTitleBuilder);
    if(d->mainTitle)
        d->mainTitle->initilizeUI();
    return d->mainTitle;
}



void QPMessageBoxTitleBuilderPrivate::init()
{
    mainTitle = new QPUITitle;
}
