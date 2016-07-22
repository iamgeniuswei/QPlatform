#include "qpmaintitlebuilder.h"
#include "private/qpmaintitlebuilder_p.h"
#include <QLabel>
#include "qpuiiconbutton.h"
#include "qpuititle.h"
#include <QStyle>
#include <QWidget>
QPMainTitleBuilder::QPMainTitleBuilder(QObject *parent) : QPUITitleBuilder(parent),d_ptr(new QPMainTitleBuilderPrivate)
{
    Q_D(QPMainTitleBuilder);
    d->init();
}

void QPMainTitleBuilder::buildLogo()
{
    Q_D(QPMainTitleBuilder);
    QLabel *logo = nullptr;
    logo = new QLabel(d->mainTitle);
    if(logo && d->mainTitle)
    {
        logo->setObjectName("MTlogo");
//        logo->setPixmap(logo->style()->standardPixmap(QStyle::SP_MessageBoxWarning));
        d->mainTitle->addTitleLogo(logo);
    }
}

void QPMainTitleBuilder::buildText()
{
    Q_D(QPMainTitleBuilder);
    QLabel *text = nullptr;
    text = new QLabel(d->mainTitle);
    if(text && d->mainTitle)
    {
        text->setObjectName("MTtext");
        d->mainTitle->addTitleText(text);
    }

    QLabel *subtext = nullptr;
    subtext = new QLabel(d->mainTitle);
    if(subtext && d->mainTitle)
    {
        subtext->setObjectName("MTsubtext");
        d->mainTitle->addSubTitleText(subtext);
    }
}

void QPMainTitleBuilder::buildUserBtn()
{

}

void QPMainTitleBuilder::buildSysBtn()
{
    Q_D(QPMainTitleBuilder);
//    QPushButton *closeBtn = nullptr;
//    closeBtn = new QPushButton(d->mainTitle);
//    if(closeBtn && d->mainTitle)
//    {
//        closeBtn->setObjectName("closeBtn");

//        closeBtn->setIcon(closeBtn->style()->standardIcon(QStyle::SP_DialogCloseButton));
//        d->mainTitle->addSysBtn(closeBtn);
//    }
}

QPUITitle *QPMainTitleBuilder::getTitleInstance()
{
    Q_D(QPMainTitleBuilder);
    if(d->mainTitle)
        d->mainTitle->initilizeUI();
    return  d->mainTitle;
}



void QPMainTitleBuilderPrivate::init()
{
    mainTitle = new QPUITitle;
}
