#include "qpuipopupwindowdirector.h"
#include "qpuipopupwindowbuilder.h"
QPUIPopupWindowDirector::QPUIPopupWindowDirector(QObject *parent) : QObject(parent)
{

}

void QPUIPopupWindowDirector::buildPopupWindow(QPUIPopupWindowBuilder *_builder)
{
    if(_builder)
    {
        _builder->buildTitle();
        _builder->buildContentArea();
    }
}

