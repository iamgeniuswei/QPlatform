#include "pagewidget.h"
#include "iconbutton.h"
#include <QKeyEvent>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QTableView>
#include <QHeaderView>
#include "sqlhelper.h"
#include "sqlworkthread.h"
#include <QSqlQueryModel>
#include "no_focus_delegate.h"
#include <QDebug>
#include <QMessageBox>

PageWidget::PageWidget(QWidget *parent):CustomWidget(parent),
    _totalPage(0),
    _totalRecord(0),
    _currentPage(0),
    _recordStep(1),
    _recordIndex(0),
    _tableName(QString())
{
    initilizeUI();
    initilizeSignal();
//    setMinimumSize(800, 640);

    connect(dataView,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(turnDetail()));
    connect(dataView,SIGNAL(clicked(QModelIndex)),this,SLOT(getTargetID()));
//    setPageData();
//    setPageCount();
}

PageWidget::~PageWidget()
{

}

void PageWidget::setPageData()
{
    SqlWorkThread *threadA = SqlHelper::createQueryThread();
    QSqlQueryModel *model = new QSqlQueryModel;
    threadA->setSqlWorkMode(SqlWorkThread::QUERYPAGE);
    threadA->setQueryPageParameter(model,_tableName,_recordIndex,_recordStep);
    connect(threadA, SIGNAL(sendQueryPageResult(QSqlQueryModel*)), this, SLOT(showModelData(QSqlQueryModel*)));
    connect(threadA, SIGNAL(finished()), threadA, SLOT(deleteLater()));
    threadA->start();
}

void PageWidget::setPageCount()
{
    SqlWorkThread *threadB = SqlHelper::createQueryThread();
    threadB->setSqlWorkMode(SqlWorkThread::QUERYCOUNT);
    threadB->setQueryCountParameter(_tableName);
    connect(threadB, SIGNAL(sendQueryCountResult(int)), this, SLOT(showCountData(int)));
    connect(threadB,SIGNAL(finished()), threadB,SLOT(deleteLater()));
    threadB->start();
}

bool PageWidget::queryPageData()
{
    if(_tableName.isEmpty())
        return false;
    else
    {
        setPageData();
        setPageCount();
    }

}


void PageWidget::showModelData(QSqlQueryModel *model)
{
    dataView->setModel(model);
    UpdateStatus();
}

void PageWidget::showCountData(int count)
{
    _totalRecord = count;
    totalRecordLb->setText(QString::number(_totalRecord));
    _totalPage = (_totalRecord % _recordStep == 0) ? (_totalRecord / _recordStep) : (_totalRecord / _recordStep + 1);
    totalPageLb->setText(QString::number(_totalPage));
//    qDebug() << "zongYeShu" << _totalPage;
}

void PageWidget::firstBtnClicked()
{
    _recordIndex = 0;
    QSqlQueryModel *model = new QSqlQueryModel;
    SqlWorkThread *thread = SqlHelper::createQueryThread();
    thread->setSqlWorkMode(SqlWorkThread::QUERYPAGE);
//    thread->setQueryParameter(model,_tableName,_recordIndex,_recordStep);
    thread->setQueryPageParameter(model,_tableName,_recordIndex,_recordStep);//liwen
    connect(thread, SIGNAL(sendQueryPageResult(QSqlQueryModel*)), this, SLOT(showModelData(QSqlQueryModel*)));
    connect(thread,SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();
    qDebug() << "recordIndex" << _recordIndex;
//    _recordIndex += _recordStep;
}

void PageWidget::prevBtnClicked()
{
    _recordIndex -= _recordStep;
    QSqlQueryModel *model = new QSqlQueryModel;
    SqlWorkThread *thread = SqlHelper::createQueryThread();
    thread->setSqlWorkMode(SqlWorkThread::QUERYPAGE);
    thread->setQueryPageParameter(model,_tableName,_recordIndex,_recordStep);
//    thread->setQueryParameter(model,_tableName,limitIndex,_recordStep);//liwen
    connect(thread, SIGNAL(sendQueryPageResult(QSqlQueryModel*)), this, SLOT(showModelData(QSqlQueryModel*)));
    connect(thread,SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();    
    qDebug() << "recordIndex" << _recordIndex;
}

void PageWidget::nextBtnClicked()
{
    _recordIndex += _recordStep;
    QSqlQueryModel *model = new QSqlQueryModel;
    SqlWorkThread *thread = SqlHelper::createQueryThread();
    thread->setSqlWorkMode(SqlWorkThread::QUERYPAGE);
    thread->setQueryPageParameter(model,_tableName,_recordIndex,_recordStep);
    connect(thread, SIGNAL(sendQueryPageResult(QSqlQueryModel*)), this, SLOT(showModelData(QSqlQueryModel*)));
    connect(thread,SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();

    qDebug() << "recordIndex" << _recordIndex;
}

void PageWidget::lastBtnClicked()
{
    _recordIndex = _totalRecord - 1;
    QSqlQueryModel *model = new QSqlQueryModel;
    SqlWorkThread *thread = SqlHelper::createQueryThread();
    thread->setSqlWorkMode(SqlWorkThread::QUERYPAGE);
    thread->setQueryPageParameter(model,_tableName,_recordIndex,_recordStep);
    connect(thread, SIGNAL(sendQueryPageResult(QSqlQueryModel*)), this, SLOT(showModelData(QSqlQueryModel*)));
    connect(thread,SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();
    qDebug() << "recordIndex" << _recordIndex;

}

void PageWidget::OnSwitchPageButtonClick()
{
    QString szText = switchPageLE->text();
    QRegExp regExp("-?[0-9]*");
    if(!regExp.exactMatch(szText))
    {
        QMessageBox::information(this, tr("tips"), tr("Please enter a Number:"));
        return;
    }
    if(szText.isEmpty())
    {
        QMessageBox::information(this, tr("tips"), tr("Please enter the page you want to jump!"));
        return;
    }
    int pageIndex = szText.toInt();
    if(pageIndex > _totalPage || pageIndex < 1)
    {
        QMessageBox::information(this, tr("tips"), tr("The Page is Null"));
        return;
    }

//    int limitIndex = pageIndex-1;
    _recordIndex = pageIndex-1;
//    RecordQuery(limitIndex);
//    currentPage = pageIndex;
//    UpdateStatus();

//    qDebug() << "xianshidijiye" << limitIndex;
    QSqlQueryModel *model = new QSqlQueryModel;
    SqlWorkThread *thread = SqlHelper::createQueryThread();
    thread->setSqlWorkMode(SqlWorkThread::QUERYPAGE);
    thread->setQueryPageParameter(model,_tableName,_recordIndex,_recordStep);
    connect(thread, SIGNAL(sendQueryPageResult(QSqlQueryModel*)), this, SLOT(showModelData(QSqlQueryModel*)));
    connect(thread,SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();


}

void PageWidget::getTargetID()
{
    QAbstractItemModel *models=dataView->model();
    int rowNum=dataView->currentIndex().row();
    QModelIndex indextemp=models->index(rowNum,0);
    QVariant id=models->data(indextemp);
    qDebug()<<"Target id is:"<<id.toString().toInt();
    int targetId=id.toString().toInt();
    emit returnTargetId(targetId);//获得Id
}

void PageWidget::turnDetail()
{
    QAbstractItemModel *models=dataView->model();
    int rowNum=dataView->currentIndex().row();
    QModelIndex indextemp=models->index(rowNum,0);
    QVariant id=models->data(indextemp);
    qDebug()<<"The id is:"<<id.toString().toInt();
    int targetId=id.toString().toInt();
    emit returnTargetId(targetId);//获得Id
    emit turnIndex(1);//详细页面默认为1
}

void PageWidget::updateData()
{

}

void PageWidget::initilizeUI()
{
    mainLayout = new QVBoxLayout;
    mainLayout->setMargin(0);
    constructOperateLayout();
    constructTableView();
    mainLayout->addWidget(dataView);
    mainLayout->addLayout(operateLayout);
    setLayout(mainLayout);
    ///
    /// \brief setMinimumWidth
    ///
//    setMinimumWidth(500);
}

void PageWidget::initilizeSignal()
{
    if(firstBtn && prevBtn && nextBtn && lastBtn)
    {
        connect(firstBtn,SIGNAL(clicked()), this, SLOT(firstBtnClicked()));
        connect(prevBtn, SIGNAL(clicked()), this, SLOT(prevBtnClicked()));
        connect(nextBtn, SIGNAL(clicked()), this, SLOT(nextBtnClicked()));
        connect(lastBtn, SIGNAL(clicked()), this, SLOT(lastBtnClicked()));
    }
}

void PageWidget::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Enter||event->key()==Qt::Key_Return)
    {
        this->OnSwitchPageButtonClick();
    }
}

QString PageWidget::nextBtnIcon() const
{
    return _nextBtnIcon;
}

void PageWidget::setNextBtnIcon(const QString &nextBtnIcon)
{
    _nextBtnIcon = nextBtnIcon;
    nextBtn->setIconPath(_nextBtnIcon);
}

QString PageWidget::prevBtnIcon() const
{
    return _prevBtnIcon;
}

void PageWidget::setPrevBtnIcon(const QString &prevBtnIcon)
{
    _prevBtnIcon = prevBtnIcon;
    prevBtn->setIconPath(_prevBtnIcon);
}

QString PageWidget::firstBtnIcon() const
{
    return _firstBtnIcon;
}

void PageWidget::setFirstBtnIcon(const QString &firstBtnIcon)
{
    _firstBtnIcon = firstBtnIcon;
    firstBtn->setIconPath(_firstBtnIcon);
}

QString PageWidget::lastBtnIcon() const
{
    return _lastBtnIcon;
}

void PageWidget::setLastBtnIcon(const QString &lastBtnIcon)
{
    _lastBtnIcon = lastBtnIcon;
    lastBtn->setIconPath(_lastBtnIcon);
}

void PageWidget::constructOperateLayout()
{
    operateLayout = new QHBoxLayout;
    firstBtn = new IconButton;
    prevBtn = new IconButton;
    nextBtn = new IconButton;
    lastBtn = new IconButton;

    switchPageLE = new QLineEdit;
    switchPageLE->setFixedWidth(80);

    totalPageTextLb = new QLabel(tr("Total"));
    totalRecordTextLb = new QLabel(tr("Total"));
    pageTextLb = new QLabel(tr("Pages"));
    recordTextLb = new QLabel(tr("Records"));
    totalPageLb = new QLabel(QString::number(_totalPage,10));
    totalRecordLb = new QLabel(QString::number(_totalRecord,10));

    operateLayout->addStretch();
    layoutA = new QHBoxLayout;

    layoutA->addWidget(firstBtn,0,Qt::AlignHCenter);
    layoutA->addWidget(prevBtn,0,Qt::AlignHCenter);
    layoutA->addWidget(switchPageLE,0,Qt::AlignHCenter);
    layoutA->addWidget(totalPageTextLb,0,Qt::AlignHCenter);
    layoutA->addWidget(totalPageLb,0,Qt::AlignHCenter);
    layoutA->addWidget(pageTextLb,0,Qt::AlignHCenter);
    layoutA->addWidget(nextBtn,0,Qt::AlignHCenter);
    layoutA->addWidget(lastBtn,0,Qt::AlignHCenter);
    operateLayout->addLayout(layoutA);

    layoutB = new QHBoxLayout;

    operateLayout->addStretch();
    layoutB->addWidget(totalRecordTextLb,0,Qt::AlignRight);
    layoutB->addWidget(totalRecordLb,0,Qt::AlignRight);
    layoutB->addWidget(recordTextLb,0,Qt::AlignRight);
    operateLayout->addLayout(layoutB);
}

void PageWidget::constructTableView()
{
    dataView = new QTableView;
    dataView->verticalHeader()->hide();
    dataView->setSelectionBehavior(QAbstractItemView::SelectRows);//select one row every time.
    dataView->horizontalHeader()->setHighlightSections(false);//
    dataView->horizontalHeader()->setStretchLastSection(true);
    dataView->setSelectionMode(QAbstractItemView::SingleSelection);
    dataView->setAlternatingRowColors(true);
    dataView->setItemDelegate(new NofocusDelegate);
}

void PageWidget::UpdateStatus()
{
//    QString szCurrentText = tr("Current Page No %1 ").arg(QString::number(currentPage));
//    currentPageLabel->setText(szCurrentText);
    if(_recordIndex == 0)
    {
        if(_totalRecord==1)
        {
            nextBtn->setBtnStatus(IconButton::DISABLE);
            lastBtn->setBtnStatus(IconButton::DISABLE);
            nextBtn->setEnabled(false);
            lastBtn->setEnabled(false);
        }
        else
        {
            nextBtn->setEnabled(true);
            lastBtn->setEnabled(true);
            nextBtn->setBtnStatus(IconButton::NORMAL);
            lastBtn->setBtnStatus(IconButton::NORMAL);
        }
        prevBtn->setBtnStatus(IconButton::DISABLE);
        firstBtn->setBtnStatus(IconButton::DISABLE);
        prevBtn->setEnabled(false);
        firstBtn->setEnabled(false);

    }
    else if(_recordIndex == _totalRecord - 1)
    {
        prevBtn->setEnabled(true);
        firstBtn->setEnabled(true);
        prevBtn->setBtnStatus(IconButton::NORMAL);
        firstBtn->setBtnStatus(IconButton::NORMAL);
        nextBtn->setBtnStatus(IconButton::DISABLE);
        lastBtn->setBtnStatus(IconButton::DISABLE);
        nextBtn->setEnabled(false);
        lastBtn->setEnabled(false);
    }
    else
    {
        prevBtn->setEnabled(true);
        nextBtn->setEnabled(true);
        firstBtn->setEnabled(true);
        lastBtn->setEnabled(true);
        prevBtn->setBtnStatus(IconButton::NORMAL);
        firstBtn->setBtnStatus(IconButton::NORMAL);
        nextBtn->setBtnStatus(IconButton::NORMAL);
        lastBtn->setBtnStatus(IconButton::NORMAL);
    }
}
QString PageWidget::tableName() const
{
    return _tableName;
}

void PageWidget::setTableName(const QString &tableName)
{
    _tableName = tableName;
}

int PageWidget::recordStep() const
{
    return _recordStep;
}

void PageWidget::setRecordStep(int recordStep)
{
    _recordStep = recordStep;
}

int PageWidget::recordIndex() const
{
    return _recordIndex;
}

void PageWidget::setRecordIndex(int recordIndex)
{
    _recordIndex = recordIndex;
}


