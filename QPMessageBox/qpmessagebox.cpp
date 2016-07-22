#include "qpmessagebox.h"
#include "private/qpmessagebox_p.h"
#include "qpmessageboxarea.h"
#include "qpuititle.h"
#include "qpmessageboxtitlebuilder.h"
#include "qpuititledirector.h"
#include "qpuiwidget.h"
QPMessageBox::QPMessageBox(QWidget *parent) : QPUIPopupWindow(new QPMessageBoxPrivate(this), parent)
{
    Q_D(QPMessageBox);
    d->init();
    addTitle(d->title);
    addContentArea((QPUIWidget*)(d->area));
    initilizeUI();
}

void QPMessageBox::setInformativeText(const QString &text)
{
    Q_D(QPMessageBox);
    if(d->area)
    {
        d->area->setInformativeText(text);
    }
}





void QPMessageBoxPrivate::init()
{
    area = new QPMessageBoxArea(q_ptr);
    QPMessageBoxTitleBuilder *builder = new QPMessageBoxTitleBuilder;
    QPUITitleDirector *director = new QPUITitleDirector;
    director->buildTitle(builder);
    title = builder->getTitleInstance();
    title->setParent(q_ptr);
}
