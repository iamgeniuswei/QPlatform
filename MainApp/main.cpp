#include "widget.h"
#include <QApplication>
#include <QTranslator>
#include <QFile>
#include "form.h"
#include "qperrorinfoqueue.h"
#include "qperrorinfo.h"
#include <QDebug>
#include <QtDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    QPrivateSqlHelper::createObject();
//    QPrivateSqlHelper::createModelObject();
//    QPSqlConnection *conn = new QPSqlConnection;
////    qDebug() << conn->ConnectionToDBByName("",\
////                               "TaskDB",\
////                               "192.168.1.201",\
////                               1521,\
////                               "ORCL",\
////                               "ronaldo",\
////                               "qhtf20150622");
//    qDebug() << conn->ConnectionToDBByDefault("QOCI",\
//                               "192.168.1.226",\
//                               1521,\
//                               "ORCL",\
//                               "XYFX2",\
//                               "123456");
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

    Form w;
    w.show();

    qDebug() << queue->getErrorCount();
    queue->addErrorInfo(100, "121212");
    qDebug() << queue->getErrorCount();

    queue->addErrorInfo(200, "dfadfafa");
    qDebug() << queue->getErrorCount();

    QPErrorInfo *info1 = new QPErrorInfo(300, "dfdfas");
    queue->addErrorInfo(info1);
    qDebug() << queue->getErrorCount();

    QPErrorInfo *info = queue->getLastError();
    if(info)
        qDebug() << info->errorNo() << info->errorMsg();
    qDebug() << queue->getErrorCount();

    info = queue->getLastError();
    if(info)
        qDebug() << info->errorNo() << info->errorMsg();
    qDebug() << queue->getErrorCount();
    info = queue->getLastError();
    if(info)
        qDebug() << info->errorNo() << info->errorMsg();
    qDebug() << queue->getErrorCount();

    return a.exec();
}
