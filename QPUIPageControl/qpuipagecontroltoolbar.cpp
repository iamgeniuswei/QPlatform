#include "qpuipagecontroltoolbar.h"
#include "private/dataoperationwidget_p.h"
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QRegExp>
#include <QDebug>
#include "qpuiiconbutton.h"
#include <QGridLayout>
QPUIPageControlToolBar::QPUIPageControlToolBar(QWidget *parent) :
    QPUIWidget(parent),
    d_ptr(new QPUIPageControlToolBarPrivate(this))
{
    setBorderColor(QColor(196, 196, 196));/*
    setInnerColor(QColor(252, 254, 255));*/
    Q_D(QPUIPageControlToolBar);
    d->init();
    initilizeUI();
    initilizeSignal();
}

void QPUIPageControlToolBar::initilizeUI()
{
    Q_D(QPUIPageControlToolBar);
    if(d->mainLayout)
    {
        d->mainLayout->setMargin(0);
        d->mainLayout->addStretch();
        if(d->firstBtn)
        {
            d->firstBtn->setObjectName("firstBtn");
            d->mainLayout->addWidget(d->firstBtn, 0, Qt::AlignHCenter);
        }
        if(d->prevBtn)
        {
            d->prevBtn->setObjectName("prevBtn");
            d->mainLayout->addWidget(d->prevBtn, 0, Qt::AlignHCenter);
        }
        if(d->switchPageLE)
        {
            d->switchPageLE->setObjectName("UIPageControlLineEdit");
            d->mainLayout->addWidget(d->switchPageLE, 0, Qt::AlignHCenter);
        }
        if(d->nextBtn)
        {
            d->nextBtn->setObjectName("nextBtn");
            d->mainLayout->addWidget(d->nextBtn, 0, Qt::AlignHCenter);
        }
        if(d->lastBtn)
        {
            d->lastBtn->setObjectName("lastBtn");
            d->mainLayout->addWidget(d->lastBtn, 0, Qt::AlignHCenter);
        }
        d->mainLayout->addStretch();

        if(d->currentRecordLb)
        {
            d->currentRecordLb->setObjectName("UIPageControlLabel");
            d->mainLayout->addWidget(d->currentRecordLb, 0, Qt::AlignRight);
        }

        if(d->totalRecordLb)
        {
            d->totalRecordLb->setObjectName("UIPageControlLabel");
            d->mainLayout->addWidget(d->totalRecordLb, 0, Qt::AlignRight);
        }
        if(d->totalPageLb)
        {
            d->totalPageLb->setObjectName("UIPageControlLabel");
            d->mainLayout->addWidget(d->totalPageLb, 0, Qt::AlignRight);
        }
        d->mainLayout->addSpacing(30);
        setLayout(d->mainLayout);
    }
}

void QPUIPageControlToolBar::initilizeSignal()
{
    Q_D(QPUIPageControlToolBar);
    if(d->firstBtn)
    {
        connect(d->firstBtn, SIGNAL(clicked()),\
                this, SIGNAL(showFirstPage()));
    }
    if(d->prevBtn)
    {
        connect(d->prevBtn, SIGNAL(clicked()),\
                this, SIGNAL(showPrevPage()));
    }
    if(d->nextBtn)
    {
        connect(d->nextBtn, SIGNAL(clicked()),\
                this, SIGNAL(showNextPage()));
    }
    if(d->lastBtn)
    {
        connect(d->lastBtn, SIGNAL(clicked()),\
                this, SIGNAL(showLastPage()));
    }
    if(d->switchPageLE)
    {
        connect(d->switchPageLE, SIGNAL(returnPressed()),\
                this, SLOT(switchPage()));
    }
}

void QPUIPageControlToolBar::updateTotalRecord(int page, int record)
{
    Q_D(QPUIPageControlToolBar);
    d->_totalPage = page;
    d->_totalRecord = record;
    d->totalPageStr = (QString(QObject::tr("total %1 page"))).arg(QString::number(d->_totalPage));
    d->totalRecordStr = QString(QObject::tr("total %1 record")).arg(QString::number(d->_totalRecord));
//    currentRecordStr = QString(QObject::tr("%1 - %2")).arg(QString::number(_startRecord)).arg(QString::number(_endRecord));

    if(d->totalPageLb)
        d->totalPageLb->setText(d->totalPageStr);
    if(d->totalRecordLb)
        d->totalRecordLb->setText(d->totalRecordStr);
}

void QPUIPageControlToolBar::updateCurrentRecord(int start, int end)
{
    Q_D(QPUIPageControlToolBar);
    if(d->currentRecordLb)
        d->currentRecordLb->setText(d->currentRecordStr);
}

void QPUIPageControlToolBar::updateBtnStatus(int index)
{
    Q_D(QPUIPageControlToolBar);
    switch (index) {
    case 0:
    case 1:
    {
        //TODO: QPUIIconButton;
//        d->nextBtn->setBtnStatus(QPUIIconButton::DISABLE);
//        d->lastBtn->setBtnStatus(QPUIIconButton::DISABLE);
//        d->nextBtn->setEnabled(false);
//        d->lastBtn->setEnabled(false);
//        d->prevBtn->setBtnStatus(QPUIIconButton::DISABLE);
//        d->firstBtn->setBtnStatus(QPUIIconButton::DISABLE);
//        d->prevBtn->setEnabled(false);
//        d->firstBtn->setEnabled(false);
        break;
    }
    case 2:
    {
//        d->nextBtn->setEnabled(true);
//        d->lastBtn->setEnabled(true);
//        d->nextBtn->setBtnStatus(QPUIIconButton::NORMAL);
//        d->lastBtn->setBtnStatus(QPUIIconButton::NORMAL);
//        d->prevBtn->setBtnStatus(QPUIIconButton::DISABLE);
//        d->firstBtn->setBtnStatus(QPUIIconButton::DISABLE);
//        d->prevBtn->setEnabled(false);
//        d->firstBtn->setEnabled(false);
        break;
    }
    case 3:
    {
//        d->prevBtn->setEnabled(true);
//        d->firstBtn->setEnabled(true);
//        d->prevBtn->setBtnStatus(QPUIIconButton::NORMAL);
//        d->firstBtn->setBtnStatus(QPDynamicIconButton::NORMAL);
//        d->nextBtn->setBtnStatus(QPUIIconButton::DISABLE);
//        d->lastBtn->setBtnStatus(QPUIIconButton::DISABLE);
//        d->nextBtn->setEnabled(false);
//        d->lastBtn->setEnabled(false);
        break;
    }
    case 4:
    {
//        d->prevBtn->setEnabled(true);
//        d->nextBtn->setEnabled(true);
//        d->firstBtn->setEnabled(true);
//        d->lastBtn->setEnabled(true);
//        d->prevBtn->setBtnStatus(QPUIIconButton::NORMAL);
//        d->firstBtn->setBtnStatus(QPUIIconButton::NORMAL);
//        d->nextBtn->setBtnStatus(QPUIIconButton::NORMAL);
//        d->lastBtn->setBtnStatus(QPDynamicIconButton::NORMAL);
        break;
    }
    default:
        break;
    }
}

void QPUIPageControlToolBar::switchPage()
{
    Q_D(QPUIPageControlToolBar);
    QString pageText;
    if(d->switchPageLE)
    {
        pageText = d->switchPageLE->text();
        d->switchPageLE->selectAll();
    }


    if(pageText.isEmpty())
    {
        //TODO: QPMessageBox;
//        QPMessageBox *msgBox = new QPMessageBox(tr("tips"), tr("Please enter a Number!"),\
//                                                tr(""), QPMessageBox::Critical);
//        msgBox->exec();
//        delete msgBox;
        return;
    }

    QRegExp regExp("-?[0-9]*");
    if(!regExp.exactMatch(pageText))
    {
        //TODO: QPMEssageBox;
//        QPMessageBox *msgBox = new QPMessageBox(tr("tips"), tr("Please enter a Number!"),\
//                                                tr(""), QPMessageBox::Critical);
//        msgBox->exec();
//        delete msgBox;
        return;
    }
    int switchpage = pageText.toInt();
    emit switchPageTo(switchpage);
}



void QPUIPageControlToolBarPrivate::init()
{    
    mainLayout = new (std::nothrow) QHBoxLayout(q_ptr);
    firstBtn = new (std::nothrow) QPUIIconButton(q_ptr);
    prevBtn = new (std::nothrow) QPUIIconButton(q_ptr);
    nextBtn = new (std::nothrow) QPUIIconButton(q_ptr);
    lastBtn = new (std::nothrow) QPUIIconButton(q_ptr);
    switchPageLE = new (std::nothrow) QLineEdit(q_ptr);

    totalPageLb = new (std::nothrow) QLabel(q_ptr);
    totalRecordLb = new (std::nothrow) QLabel(q_ptr);
    currentRecordLb = new (std::nothrow) QLabel(q_ptr);

    totalPageStr = (QString(QObject::tr("total %1 page"))).arg(QString::number(_totalPage));
    totalRecordStr = QString(QObject::tr("total %1 record")).arg(QString::number(_totalRecord));
    currentRecordStr = QString(QObject::tr("%1 - %2")).arg(QString::number(_startRecord)).arg(QString::number(_endRecord));

    if(totalPageLb)
        totalPageLb->setText(totalPageStr);
    if(totalRecordLb)
        totalRecordLb->setText(totalRecordStr);
    if(currentRecordLb)
        currentRecordLb->setText(currentRecordStr);


}
