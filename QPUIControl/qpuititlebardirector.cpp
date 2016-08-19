#include "qpuititlebardirector.h"
#include "qpuititlebarbuilder.h"
#include <QDebug>
QPUITitleBarDirector::QPUITitleBarDirector(QObject *parent) : QObject(parent)
{

}

void QPUITitleBarDirector::buildTitle(QPUITitleBarBuilder *builder)
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
        qDebug() << "TitleBar Builder is nullptr, build title bar failture.";
    }
}

