#include "qpuititledirector.h"
#include "qpuititlebuilder.h"
#include <QDebug>
QPUITitleDirector::QPUITitleDirector(QObject *parent) : QObject(parent)
{

}

void QPUITitleDirector::buildTitle(QPUITitleBuilder *builder)
{
    if(builder)
    {
        builder->buildLogo();
        builder->buildText();
        builder->buildUserBtn();
        builder->buildSysBtn();
    }
    else
    {
        qDebug() << "";
    }
}

