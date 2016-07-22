#include "qpuiwindowdirector.h"
#include "qpuiwindowbuilder.h"
QPUIWindowDirector::QPUIWindowDirector(QObject *parent) : QObject(parent)
{

}

void QPUIWindowDirector::buildWindow(QPUIWindowBuilder *_builder)
{
    if(_builder)
    {
        _builder->buildTitle();
        _builder->buildNavigationBar();
        _builder->buildContentArea();
        _builder->buildStatusBar();
    }
}

