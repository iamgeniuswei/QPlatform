#include "qpuipagecontrol.h"
#include "pagewidget_p.h"
#include "qpuipagecontroltoolbar.h"
#include <QKeyEvent>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QTableView>
#include <QHeaderView>
#include "sqlhelper.h"
#include "qpsqlworkthread.h"
#include <QSqlQueryModel>
#include "no_focus_delegate.h"
#include <QDebug>
#include <QMessageBox>
//#include "qpmessagebox.h"
#include <QTreeView>
#include <QMenu>
//#include "qperrorinfo.h"
//#include "qperrorinfoqueue.h"
#include "datetimedelegate.h"
#include <QSortFilterProxyModel>
#include "qpquerymodel.h"


QPUIPageControl::QPUIPageControl(QWidget *parent)
    :QPUIWidget(parent),
    d_ptr(new QPUIPageControlPrivate(this))
{
    Q_D(QPUIPageControl);
    d->init();
    initilizeUI();
    initilizeSignal();
    setMinimumHeight(600);
}

QPUIPageControl::~QPUIPageControl()
{    
    Q_D(QPUIPageControl);
    delete d;
}

void QPUIPageControl::setPageData()
{
    Q_D(QPUIPageControl);
    QPSqlWorkThread *threadA = SqlHelper::createQueryThread();
    if(threadA)
    {
        threadA->setSqlWorkMode(QPSqlWorkThread::QUERYPAGE);
        threadA->setQueryPageParameter(d->_recordIndex,d->_recordStep,d->_tableName,d->_condition, d->_realTableName, d->_connName);
        connect(threadA, SIGNAL(sendQueryPageResult(QPQueryModel*)), this, SLOT(showModelData(QPQueryModel*)));
        connect(threadA, SIGNAL(sendErrorMsg()), this, SLOT(showErrorMsg()));
        connect(threadA, SIGNAL(finished()), threadA, SLOT(deleteLater()));
        threadA->start();
    }
}

void QPUIPageControl::setPageCount()
{
    Q_D(QPUIPageControl);
    QPSqlWorkThread *threadB = SqlHelper::createQueryThread();
    if(threadB)
    {
        threadB->setSqlWorkMode(QPSqlWorkThread::QUERYCOUNT);
        threadB->setQueryCountParameter(d->_tableName, d->_condition, d->_realTableName, d->_connName);
        connect(threadB, SIGNAL(sendQueryCountResult(int)), this, SLOT(showCountData(int)));
        connect(threadB, SIGNAL(sendErrorMsg()), this, SLOT(showErrorMsg()));
        connect(threadB,SIGNAL(finished()), threadB,SLOT(deleteLater()));
        threadB->start();
    }
}

bool QPUIPageControl::queryPageData()
{
    Q_D(QPUIPageControl);
    if(d->_tableName.isEmpty())
        return false;
    else
    {
        setPageData();
        setPageCount();
    }
    return true;
}

QVariant QPUIPageControl::getSelectedFieldValue(int column)
{
    Q_D(QPUIPageControl);
    if(d->dataView)
    {
        QAbstractItemModel *models = d->dataView->model();
        int rowNum = d->dataView->currentIndex().row();
        QModelIndex indextemp;
        if(column <= models->columnCount())
            indextemp = models->index(rowNum,column);
        QVariant data = models->data(indextemp);
        return data;
    }
    return -1;
}

void QPUIPageControl::showModelData(QPQueryModel *model)
{
    Q_D(QPUIPageControl);
    d->tempModel = model;
    qDebug() << model;
    if(d->dataView)
    {
        QPQueryModel *currentModel = qobject_cast<QPQueryModel*>( d->dataView->model());
        qDebug() << currentModel;
        delete currentModel;
    }
    if(model && d->dataView)
    {
        qDebug()<< model->columnCount();
        model->removeColumn(model->columnCount()-1);
        model->setHeaderLabel(d->_headerLabel);

        d->dataView->setModel(model);

        emit updateCurrentRecord(d->_recordIndex+1, d->_recordIndex + model->rowCount());
        UpdateStatus();
    }
}

void QPUIPageControl::showCountData(int count)
{
    Q_D(QPUIPageControl);
    d->_totalRecord = count;
    if(d->_recordStep > 0)
    {
        d->_totalPage = (d->_totalRecord % d->_recordStep == 0) ? (d->_totalRecord / d->_recordStep) : (d->_totalRecord / d->_recordStep + 1);
    }
    emit updateTotalRecord(d->_totalPage, d->_totalRecord);
    UpdateStatus();
}

void QPUIPageControl::showErrorMsg()
{
//    QPErrorInfoQueue *queue = QPErrorInfoQueue::getInstance();
//    QPErrorInfo info = queue->QPErrorInfoQueue::getLastError();
//    QPMessageBox *msgBox = new QPMessageBox(tr("Error"), info.errorMsg(),\
//                                            tr(""), QPMessageBox::Critical);
//    msgBox->exec();
//    delete msgBox;
}

void QPUIPageControl::showFirstPage()
{
    Q_D(QPUIPageControl);
    d->_recordIndex = 0;
    QPSqlWorkThread *thread = SqlHelper::createQueryThread();
    if(thread)
    {
        thread->setSqlWorkMode(QPSqlWorkThread::QUERYPAGE);
        thread->setQueryPageParameter(d->_recordIndex,d->_recordStep,d->_tableName,d->_condition, d->_realTableName, d->_connName);
        connect(thread, SIGNAL(sendQueryPageResult(QPQueryModel*)), this, SLOT(showModelData(QPQueryModel*)));
        connect(thread, SIGNAL(sendErrorMsg()), this, SLOT(showErrorMsg()));
        connect(thread,SIGNAL(finished()), thread, SLOT(deleteLater()));
        thread->start();
    }
}

void QPUIPageControl::showPrevPage()
{
    Q_D(QPUIPageControl);
    d->_recordIndex -= d->_recordStep;
    QPSqlWorkThread *thread = SqlHelper::createQueryThread();
    if(thread)
    {
        thread->setSqlWorkMode(QPSqlWorkThread::QUERYPAGE);
        thread->setQueryPageParameter(d->_recordIndex,d->_recordStep,d->_tableName,d->_condition, d->_realTableName, d->_connName);
        connect(thread, SIGNAL(sendQueryPageResult(QPQueryModel*)), this, SLOT(showModelData(QPQueryModel*)));
        connect(thread, SIGNAL(sendErrorMsg()), this, SLOT(showErrorMsg()));
        connect(thread,SIGNAL(finished()), thread, SLOT(deleteLater()));
        thread->start();
    }
}

void QPUIPageControl::showNextPage()
{
    Q_D(QPUIPageControl);
    d->_recordIndex += d->_recordStep;
    QPSqlWorkThread *thread = SqlHelper::createQueryThread();
    if(thread)
    {
        thread->setSqlWorkMode(QPSqlWorkThread::QUERYPAGE);
        thread->setQueryPageParameter(d->_recordIndex,d->_recordStep,d->_tableName,d->_condition, d->_realTableName, d->_connName);
        connect(thread, SIGNAL(sendQueryPageResult(QPQueryModel*)), this, SLOT(showModelData(QPQueryModel*)));
        connect(thread, SIGNAL(sendErrorMsg()), this, SLOT(showErrorMsg()));
        connect(thread,SIGNAL(finished()), thread, SLOT(deleteLater()));
        thread->start();
    }
}

void QPUIPageControl::showLastPage()
{
    Q_D(QPUIPageControl);
    d->_recordIndex = (d->_totalPage - 1)*d->_recordStep;
    QPSqlWorkThread *thread = SqlHelper::createQueryThread();
    if(thread)
    {
        thread->setSqlWorkMode(QPSqlWorkThread::QUERYPAGE);
        thread->setQueryPageParameter(d->_recordIndex,d->_recordStep,d->_tableName,d->_condition, d->_realTableName, d->_connName);
        connect(thread, SIGNAL(sendQueryPageResult(QPQueryModel*)), this, SLOT(showModelData(QPQueryModel*)));
        connect(thread, SIGNAL(sendErrorMsg()), this, SLOT(showErrorMsg()));
        connect(thread,SIGNAL(finished()), thread, SLOT(deleteLater()));
        thread->start();
    }
}

void QPUIPageControl::switchPageTo(int page)
{
//    Q_D(QPUIPageControl);
//    if(page > d->_totalPage || page < 1)
//    {
//        QPMessageBox *msgBox = new QPMessageBox(tr("tips"), tr("The page is null!"),\
//                                                tr(""), QPMessageBox::Critical);
//        msgBox->exec();
//        delete msgBox;
//        return;
//    }
//    d->_recordIndex = (page - 1)*d->_recordStep;
//    QSqlQueryModel *model = NULL;
//    model = new QSqlQueryModel;
//    QPSqlWorkThread *thread = NULL;
//    thread = SqlHelper::createQueryThread();
//    if(thread && model)
//    {
//        thread->setSqlWorkMode(QPSqlWorkThread::QUERYPAGE);
//        thread->setQueryPageParameter(d->_recordIndex,d->_recordStep,d->_tableName,d->_condition, d->_realTableName, d->_connName);
//        connect(thread, SIGNAL(sendQueryPageResult(QPQueryModel*)), this, SLOT(showModelData(QPQueryModel*)));
//        connect(thread, SIGNAL(sendErrorMsg()), this, SLOT(showErrorMsg()));
//        connect(thread,SIGNAL(finished()), thread, SLOT(deleteLater()));
//        thread->start();
//    }
}

void QPUIPageControl::getRowIDByClicked()
{
//    Q_D(QPUIPageControl);
//    if(d->dataView)
//    {
//        QAbstractItemModel *models = d->dataView->model();
//        int rowNum = d->dataView->currentIndex().row();
//        QModelIndex indextemp = models->index(rowNum,0);
//        QVariant id = models->data(indextemp);
//        int rowID=id.toString().toInt();
//        emit getTargetIDByClicked(rowID);// get row Id
//    }
}

void QPUIPageControl::getRowIDByDoubleClicked()
{
//    Q_D(QPUIPageControl);
//    if(d->dataView)
//    {
//        QAbstractItemModel *models = d->dataView->model();
//        int rowNum = d->dataView->currentIndex().row();
//        QModelIndex indextemp = models->index(rowNum,0);
//        QVariant id = models->data(indextemp);
//        int rowID=id.toString().toInt();
//        emit getTargetIDByDoubleClicked(rowID);// get row Id
//    }
}

void QPUIPageControl::mouseRightClicked(const QPoint &pos)
{
//    Q_D(QPUIPageControl);
//    if(d->dataView)
//    {
//        int height = 1.5*(d->dataView->horizontalHeader()->height());
//        QPoint pt1(0,height);
//        QPoint pt = d->dataView->mapFromGlobal(QCursor::pos()+d->dataView->pos());
//        pt-=pt1;
//        QModelIndex idx = d->dataView->indexAt(pt);
//        if(!idx.isValid())
//        {
//            d->dataView->clearSelection();
//        }
//        else
//        {
//            int isClicked = d->dataView->currentIndex().row();
//            if(isClicked!=-1 && d->commandMenu)
//                d->commandMenu->exec(QCursor::pos());
//        }
//    }
}

void QPUIPageControl::setItemDelegateForColumn(int column, QAbstractItemDelegate *delegate)
{
//    Q_D(QPUIPageControl);
//    if(d->dataView && delegate)
//    {
//        d->dataView->setItemDelegateForColumn(column, delegate);
//    }
}

void QPUIPageControl::searchInitSlot()
{
//    Q_D(QPUIPageControl);
//    d->_currentPage = 1;
//    d->_recordIndex = 0;
//    UpdateStatus();
}

void QPUIPageControl::initilizeUI()
{
    Q_D(QPUIPageControl);
    if(d->mainLayout)
    {
        d->mainLayout->setMargin(1);
        if(d->dataView)
        {
            d->dataView->setContextMenuPolicy(Qt::CustomContextMenu);
            d->dataView->verticalHeader()->setDefaultSectionSize(23);
            d->dataView->setSelectionBehavior(QAbstractItemView::SelectRows);//select one row every time.
            d->dataView->horizontalHeader()->setHighlightSections(false);//
            d->dataView->horizontalHeader()->setStretchLastSection(false);
            d->dataView->setItemDelegate(new NofocusDelegate);
            d->dataView->horizontalHeader()->setDefaultSectionSize(150);
            d->dataView->setAlternatingRowColors(true);

            d->headView = d->dataView->horizontalHeader();
            if(d->headView)
            {
                d->headView->setSortIndicator(0, Qt::AscendingOrder);
                d->headView->setSortIndicatorShown(true);
            }
            d->mainLayout->addWidget(d->dataView);
        }
        if(d->dataOperation)
        {
            d->mainLayout->addWidget(d->dataOperation, 0, Qt::AlignBottom /*| Qt::AlignHCenter*/);
        }
        setLayout(d->mainLayout);
    }
}

void QPUIPageControl::initilizeSignal()
{
//    Q_D(QPUIPageControl);
//    if(d->dataOperation)
//    {
//        connect(d->dataOperation,SIGNAL(showFirstPage()), this, SLOT(showFirstPage()));
//        connect(d->dataOperation, SIGNAL(showPrevPage()), this, SLOT(showPrevPage()));
//        connect(d->dataOperation, SIGNAL(showNextPage()), this, SLOT(showNextPage()));
//        connect(d->dataOperation, SIGNAL(showLastPage()), this, SLOT(showLastPage()));
//        connect(d->dataOperation, SIGNAL(switchPageTo(int)), this, SLOT(switchPageTo(int)));
//        connect(this, SIGNAL(updateTotalRecord(int,int)), d->dataOperation, SLOT(updateTotalRecord(int,int)));
//        connect(this, SIGNAL(updateCurrentRecord(int,int)), d->dataOperation, SLOT(updateCurrentRecord(int,int)));
//        connect(this, SIGNAL(updateBtnStatus(int)), d->dataOperation, SLOT(updateBtnStatus(int)));

//    }
//    if(d->dataView)
//    {
//        connect(d->dataView,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(getRowIDByDoubleClicked()));
//        connect(d->dataView,SIGNAL(clicked(QModelIndex)),this,SLOT(getRowIDByClicked()));
//        connect(d->dataView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(mouseRightClicked(QPoint)));
//    }
//    if(d->headView)
//        connect(d->headView, SIGNAL(sectionClicked(int)), this, SLOT(viewSort(int)));
}

void QPUIPageControl::UpdateStatus()
{
//    Q_D(QPUIPageControl);
//    if(d->_recordIndex == 0)
//    {
//        if(d->_totalRecord==1)
//        {
//            emit updateBtnStatus(0);
//        }
//        else if(d->_recordStep > d->_totalRecord||d->_recordStep == d->_totalRecord)
//        {
//            emit updateBtnStatus(1);
//        }
//        else
//        {
//            emit updateBtnStatus(2);
//        }
//    }
//    else if(d->_recordIndex == (d->_totalPage - 1)*d->_recordStep)
//    {
//        emit updateBtnStatus(3);
//    }
//    else
//    {
//        emit updateBtnStatus(4);
//    }
}
QString QPUIPageControl::condition() const
{
    Q_D(const QPUIPageControl);
    return d->_condition;
}

void QPUIPageControl::setCondition(const QString &condition)
{
    Q_D(QPUIPageControl);
    d->_condition = condition;
}

QString QPUIPageControl::connName() const
{
    Q_D(const QPUIPageControl);
    return d->_connName;

}

void QPUIPageControl::setConnName(const QString &connName)
{
    Q_D(QPUIPageControl);
    d->_connName = connName;
}

QStringList QPUIPageControl::headerLabel() const
{
    Q_D(const QPUIPageControl);
    return d->_headerLabel;

}

void QPUIPageControl::setHeaderLabel(const QStringList &headerLabel)
{
    Q_D(QPUIPageControl);
    d->_headerLabel = headerLabel;
}

void QPUIPageControl::setCommandMenu(QMenu *menu)
{
    Q_D(QPUIPageControl);
    d->commandMenu = menu;
}

QTableView *QPUIPageControl::getTableView()
{
    Q_D(QPUIPageControl);
    return d->dataView;
}

QString QPUIPageControl::tableName() const
{
    Q_D(const QPUIPageControl);
    return d->_tableName;
}

void QPUIPageControl::setTableName(const QString &tableName)
{
    Q_D(QPUIPageControl);
    d->_tableName = tableName;
}

QString QPUIPageControl::realTableName() const
{
    Q_D(const QPUIPageControl);
    return d->_realTableName;
}

void QPUIPageControl::setRealTableName(const QString &realTable)
{
    Q_D(QPUIPageControl);
    d->_realTableName = realTable;
}

int QPUIPageControl::recordStep() const
{
    Q_D(const QPUIPageControl);
    return d->_recordStep;
}

void QPUIPageControl::setRecordStep(int recordStep)
{
    Q_D(QPUIPageControl);
    d->_recordStep = recordStep;
}

int QPUIPageControl::recordIndex() const
{
    Q_D(const QPUIPageControl);
    return d->_recordIndex;
}

void QPUIPageControl::setRecordIndex(int recordIndex)
{
    Q_D(QPUIPageControl);
    d->_recordIndex = recordIndex;
}

void QPUIPageControl::viewSort(int column)
{
//    Q_D(QPUIPageControl);
//    QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel;
//    proxyModel->setSourceModel(d->tempModel);
//    d->dataView->setModel(proxyModel);
//    proxyModel->sort(column,d->headView->sortIndicatorOrder());
}


void QPUIPageControlPrivate::init()
{
    //composite design pattern;
    mainLayout = new (std::nothrow) QVBoxLayout(q_ptr);
    dataView = new (std::nothrow) QTableView(q_ptr);
    dataOperation = new (std::nothrow) QPUIPageControlToolBar(q_ptr);

}
