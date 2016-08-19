#include "testwidget.h"
#include <QHBoxLayout>
#include <QLabel>
TestWidget::TestWidget(QWidget *parent) : QWidget(parent)
{
    setFixedSize(200,48);
    layout = new QHBoxLayout(this);
    text = new QLabel("account",this);
    sep = new QLabel(this);
    sep->setObjectName("test222");
    layout->setMargin(0);
    layout->addStretch(1);
    layout->addWidget(text,0,Qt::AlignRight);
    layout->addWidget(sep, 0, Qt::AlignRight);
    setLayout(layout);
}

QLabel *TestWidget::getText() const
{
    return text;
}

QLabel *TestWidget::getSep() const
{
    return sep;
}
