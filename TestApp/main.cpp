#include <QCoreApplication>
#include "qpsqlconnection.h"
#include <QDebug>
#include <sys/time.h>
#include <stdio.h>
#include <QSqlQuery>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

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
    printf("%d:%d\n", tv.tv_sec, tv.tv_usec);
    QSqlQuery query;
    query.prepare("INSERT INTO swiveltable(name, description) "
                  "VALUES(:name, :description)");

    for(int i=0; i<100000; i++)
    {
        query.bindValue(":name", "test");
        query.bindValue(":description", "test");
        query.exec();
    }
//    qDebug() << query.exec();
//    for(int i=0; i<10000; i++)
//    {
//        query.exec("INSERT INTO swiveltablestatus (name, description) VALUES ('test', 'test')");
//    }
//    query.exec("SELECT * FROM swiveltablestatus");
//    printf("%d\n", query.size());
    timeval tv1;
    gettimeofday(&tv1, NULL);
    printf("%d:%d\n", tv1.tv_sec, tv1.tv_usec);
    printf("%d:%d\n", tv1.tv_sec-tv.tv_sec, tv1.tv_usec-tv.tv_usec);
    return a.exec();
}
