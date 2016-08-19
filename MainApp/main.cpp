#include "widget.h"
#include <QApplication>
#include <QTranslator>
#include <QFile>
#include "form.h"
#include "qperrorinfoqueue.h"
#include "qperrorinfo.h"
#include <QDebug>
#include <QtDebug>
#include "qpsqlconnection.h"
#include <sys/time.h>


//test
#include <QLabel>
#include "qpuititlebar.h"
#include <QScopedPointer>
#include <QPushButton>
#include "qpuiiconbutton.h"
#include <QListWidget>
#include <QListWidgetItem>

#include "testform.h"
#include "testscorllarea.h"
#include "testwidget.h"
#include "qpuitimelinelist.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    QPrivateSqlHelper::createObject();
//    QPrivateSqlHelper::createModelObject();
    QPSqlConnection *conn = QPSqlConnection::getInstance();
////    qDebug() << conn->ConnectionToDBByName("",\
////                               "TaskDB",\
////                               "192.168.1.201",\
////                               1521,\
////                               "ORCL",\
////                               "ronaldo",\
////                               "qhtf20150622");
    qDebug() << conn->connectToDefaultDB("QPSQL",\
                               "127.0.0.1",\
                               5432,\
                               "ATCCSDB",\
                               "lenovo",\
                               "123456");
    qDebug() << conn->closeDefaultDB();
    qDebug() << conn->openDefaultDB();

    timeval tv;
    gettimeofday(&tv, NULL);

    for(int i=0; i<10000; i++)
    {

    }





//    delete conn;




    QFile qss(":/qss/version1");
    qss.open(QFile::ReadOnly);
    qApp->setStyleSheet(qss.readAll());
    qss.close();


    const QString langPath = ":/lang/lang_zh";
    QTranslator translator;
    translator.load(langPath);
    a.installTranslator(&translator);



    QPErrorInfoQueue *queue = QPErrorInfoQueue::getInstance();
    QPUITimeLineList *list = new QPUITimeLineList;
    list->show();

//    TestScorllArea *scroll = new TestScorllArea;
//    scroll->show();

//    TestWidget *w = new TestWidget;
//    TestWidget *w2 = new TestWidget;
//    TestWidget *w3 = new TestWidget;
////    w->show();



//    TestForm *form = new TestForm;
//    TestForm *form2 = new TestForm;
//    TestForm *form3 = new TestForm;

//    QListWidget *list = new QListWidget;
//    QListWidgetItem *item1 = new QListWidgetItem(list);

//    item1->setSizeHint(QSize(200,48));
//    QListWidgetItem *item2 = new QListWidgetItem(list);
//    item2->setSizeHint(QSize(200,48));
//    QListWidgetItem *item3 = new QListWidgetItem(list);
//    item3->setSizeHint(QSize(200,48));

//    list->setItemWidget(item1, w);
//    list->setItemWidget(item2, w2);
//    list->setItemWidget(item3, w3);
//    list->setFixedWidth(220);
//    list->setAutoScroll(false);
//    list->setSelectionRectVisible(false);
//    list->setCursor(Qt::PointingHandCursor);
//    list->show();
//    QScopedPointer<QPUIIconButton> btn(new QPUIIconButton);
//    btn->setObjectName("firstBtn");
//    btn->show();

//        QPUITitleBar *titleBar = new QPUITitleBar;

//        QLabel *logo = nullptr;
//        logo = new QLabel(titleBar);
//        if(logo)
//        {
//            logo->setObjectName("MTlogo");
//            titleBar->addTitleLogo(logo);
//        }
//        QLabel *text = nullptr;
//        text = new QLabel(titleBar);
//        if(text)
//        {
//            text->setObjectName("MTtext");
//            titleBar->addTitleText(text);
//        }

//        QLabel *subtext = nullptr;
//        subtext = new QLabel(titleBar);
//        if(subtext && titleBar)
//        {
//            subtext->setObjectName("MTsubtext");
//            titleBar->addSubTitleText(subtext);
//        }

//        QPUIIconButton *btn1 = new QPUIIconButton();
//        btn1->setObjectName("test160");
//    //    btn1->show();
//        titleBar->addCustomBtn(btn1);
//        QPUIIconButton *btn2 = new QPUIIconButton();
//        btn2->setObjectName("test160");
//    //    btn1->show();
//        titleBar->addCustomBtn(btn2);
//        QPUIIconButton *btn3 = new QPUIIconButton();
//        btn3->setObjectName("test160");
//    //    btn1->show();
//        titleBar->addCustomBtn(btn3);

//        titleBar->initilizeUI();


//    //    titleBar->show();


//    QListWidget *list = new QListWidget;
//    QPushButton *btn = new QPushButton("dfafaf");
//    QListWidgetItem *item = new QListWidgetItem(list);
//    list->setItemWidget(item, btn);

////    QListWidget *list = new QListWidget;
//    QListWidgetItem *item1 = new QListWidgetItem(list);
//    list->setItemWidget(item1, titleBar);
//    list->show();




//    Form w;
//    w.show();

//    qDebug() << queue->getErrorCount();
//    queue->addErrorInfo(100, "121212");
//    qDebug() << queue->getErrorCount();

//    queue->addErrorInfo(200, "dfadfafa");
//    qDebug() << queue->getErrorCount();

//    QPErrorInfo *info1 = new QPErrorInfo(300, "dfdfas");
//    queue->addErrorInfo(info1);
//    qDebug() << queue->getErrorCount();

//    QPErrorInfo *info = queue->getLastError();
//    if(info)
//        qDebug() << info->errorNo() << info->errorMsg();
//    qDebug() << queue->getErrorCount();

//    info = queue->getLastError();
//    if(info)
//        qDebug() << info->errorNo() << info->errorMsg();
//    qDebug() << queue->getErrorCount();
//    info = queue->getLastError();
//    if(info)
//        qDebug() << info->errorNo() << info->errorMsg();
//    qDebug() << queue->getErrorCount();

    return a.exec();
}
