#include "qpuipopupwindow.h"
#include "private/qpuipopupwindow_p.h"
#include <QVBoxLayout>
#include "qpuititlebar.h"
#include "qpuiwidget.h"
QPUIPopupWindow::QPUIPopupWindow(QWidget *parent) : QPUIWidget(parent),
    d_ptr(new QPUIPopupWindowPrivate(this))
{
    setAttribute(Qt::WA_TranslucentBackground);
    Q_D(QPUIPopupWindow);
    d->init();
}

void QPUIPopupWindow::addTitle(QPUITitleBar *title)
{
    Q_D(QPUIPopupWindow);
    if(title && d->mainLayout)
    {
        d->mainLayout->addWidget(title/*, 0, Qt::AlignTop*/);
    }
}

void QPUIPopupWindow::addContentArea(QPUIWidget *contentArea)
{
    Q_D(QPUIPopupWindow);
    if(d->contentLayout)
    {
        d->contentLayout->addWidget(contentArea);
    }
}

void QPUIPopupWindow::initilizeUI()
{
    Q_D(QPUIPopupWindow);
    addTitle(d->title);
    d->contentArea->setLayout(d->contentLayout);
    d->mainLayout->addWidget(d->contentArea);
    if(d->mainLayout)
    {
        d->mainLayout->setMargin(0);
        d->mainLayout->setSpacing(0);
        setLayout(d->mainLayout);
    }
}

QPUITitleBar *QPUIPopupWindow::getTitle() const
{
    Q_D(const QPUIPopupWindow);
    if(d)
        return d->title;
    return nullptr;
}

void QPUIPopupWindow::setTitleLogo(QLabel *logo)
{
    if(d_ptr && d_ptr->title)
    {
        d_ptr->title->addTitleLogo(logo);
    }

}

void QPUIPopupWindow::setTitleWidget(QWidget *widget)
{
    if(d_ptr && d_ptr->title)
    {
        d_ptr->title->addTitleText(widget);
    }
}

QPUIPopupWindow::QPUIPopupWindow(QPUIPopupWindowPrivate *dd, QWidget *parent):
    d_ptr(dd), QPUIWidget(parent)
{
    Q_D(QPUIPopupWindow);
    d->init();
}



void QPUIPopupWindowPrivate::init()
{
    mainLayout = new QVBoxLayout(q_ptr);
    title = new (std::nothrow) QPUITitleBar(q_ptr);
    if(title)
    {
        title->setObjectName("popupWindow");
        title->setParent(q_ptr);
        title->setAttribute(Qt::WA_TranslucentBackground);
    }
    contentArea = new (std::nothrow) QPUIWidget(q_ptr);
    contentArea->setFixedSize(300,200);
    contentLayout = new (std::nothrow) QVBoxLayout(contentArea);


}
