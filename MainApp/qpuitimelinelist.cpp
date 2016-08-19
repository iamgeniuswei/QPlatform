#include "qpuitimelinelist.h"
#include "testform.h"
#include "testwidget.h"
#include <QLabel>
QPUITimeLineList::QPUITimeLineList(QWidget *parent) : QListWidget(parent)
{

    setFixedWidth(210);
    TestWidget *w = new TestWidget;
    TestWidget *w2 = new TestWidget;
    TestWidget *w3 = new TestWidget;

    QListWidgetItem *item1 = new QListWidgetItem(this);

    item1->setSizeHint(QSize(200,48));
    QListWidgetItem *item2 = new QListWidgetItem(this);
    item2->setSizeHint(QSize(200,48));
    QListWidgetItem *item3 = new QListWidgetItem(this);
    item3->setSizeHint(QSize(200,48));
    setItemWidget(item1, w);
    setItemWidget(item2, w2);
    setItemWidget(item3, w3);

    connect(this,SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)),\
            this, SLOT(currentItemChangedSlot(QListWidgetItem*,QListWidgetItem*)));
    connect(this, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(itemClickedSlot(QListWidgetItem*)));
}

void QPUITimeLineList::itemClickedSlot(QListWidgetItem *item)
{
    QWidget *widget = itemWidget(item);
    if(widget)
    {
        TestWidget *w = qobject_cast<TestWidget*>(widget);
        QLabel *label = w->getText();
        label->setStyleSheet("color:red;");
        QLabel *sep = w->getSep();
        sep->setPixmap(QPixmap(":/img/444"));
    }
}

void QPUITimeLineList::currentItemChangedSlot(QListWidgetItem *current, QListWidgetItem *previous)
{
    QWidget *widget = itemWidget(previous);
    if(widget)
    {
        TestWidget *w = qobject_cast<TestWidget*>(widget);
        QLabel *label = w->getText();
        label->setStyleSheet("color:black;");
        QLabel *sep = w->getSep();
        sep->setPixmap(QPixmap(":/img/222"));
    }
}
