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

    for(int i=0; i<10000; i++)
    {
        query.exec("INSERT INTO swiveltablestatus (name, description) VALUES ('test', 'test')");
    }
    gettimeofday(&tv, NULL);
    printf("%d:%d\n", tv.tv_sec, tv.tv_usec);
    return a.exec();
}
