#include "qpocisqlcommand.h"
#include <QDebug>
QPOCISqlCommand::QPOCISqlCommand()
{
}

bool QPOCISqlCommand::queryPage(QPQueryModel *model, \
                                const QString &tableName, \
                                const int index, \
                                const int step,\
                                const QString &condition,\
                                const QString &connName)
{   
    QString sql;
    if(condition.isEmpty())
    {
        if(tableName.contains("T_VIEW_PKTINFO"))
        {
            sql = QString("SELECT * FROM ( SELECT A.* ,PKTID RN FROM (SELECT * FROM "\
                          + tableName
                          + ") A )WHERE RN > %1 AND RN <= %2").arg(QString::number(index)).arg(QString::number(index+step));
        }
        else
        {
            sql = QString("SELECT * FROM ( SELECT A.* ,ROWNUM RN FROM (SELECT * FROM "\
                          + tableName
                          + ") A )WHERE RN > %1 AND RN <= %2").arg(QString::number(index)).arg(QString::number(index+step));
        }

    }
    else
    {
//        if(tableName.contains("T_VIEW_PKTINFO"))
//        {
//            sql = QString("SELECT * FROM ( SELECT A.* ,PKTID RN FROM (SELECT * FROM "\
//                        + tableName\
//                        + " WHERE "\
//                        + condition
//                        +") A )WHERE RN > %1 AND RN <= %2").arg(QString::number(index)).arg(QString::number(index+step));
//        }
//        else
//        {
//            sql = QString("SELECT * FROM ( SELECT A.* ,ROWNUM RN FROM (SELECT * FROM "\
//                        + tableName\
//                        + " WHERE "\
//                        + condition
//                        +") A )WHERE RN > %1 AND RN <= %2").arg(QString::number(index)).arg(QString::number(index+step));
//        }

        sql = QString("SELECT * FROM ( SELECT A.* ,ROWNUM RN FROM (SELECT * FROM "\
                    + tableName\
                    + " WHERE "\
                    + condition
                    +") A )WHERE RN > %1 AND RN <= %2").arg(QString::number(index)).arg(QString::number(index+step));


    }
    return queryModel(model, sql, connName);

}

//bool QPOCISqlCommand::queryPage(QueryModel *model, const QString &tableName, const int index, const int step, const QString &conditon)
//{
//    QString sql;
//    if(conditon.isEmpty())
//    {
//        queryPage(model, tableName, index, step);
//    }
//    else
//    {
//        sql = QString("SELECT * FROM ( SELECT A.* ,ROWNUM RN FROM (SELECT * FROM "\
//                    + tableName\
//                    + " WHERE "\
//                    + conditon
//                    +") A )WHERE RN > %1 AND RN <= %2").arg(QString::number(index)).arg(QString::number(index+step));

//        return queryModel(model, sql);
//    }

//}

//bool QPOCISqlCommand::queryPageWithConnection(QueryModel *model, const QString &tableName, const int index, const int step, const QString &connName)
//{
//    QString sql;
//    sql = QString("SELECT * FROM ( SELECT A.* ,ROWNUM RN FROM (SELECT * FROM "\
//                  + tableName
//                  + ") A )WHERE RN > %1 AND RN <= %2").arg(QString::number(index)).arg(QString::number(index+step));
//    return queryModel(model, sql, connName);
//}

//bool QPOCISqlCommand::queryPageWithConnection(QueryModel *model, const QString &tableName, const int index, const int step, const QString &conditon, const QString &connName)
//{
//    QString sql;
//    if(conditon.isEmpty())
//    {
//        queryPageWithConnection(model, tableName, index, step, connName);
//    }
//    else
//    {
//        sql = QString("SELECT * FROM ( SELECT A.* ,ROWNUM RN FROM (SELECT * FROM "\
//                    + tableName\
//                    + " WHERE "\
//                    + conditon
//                    +") A )WHERE RN > %1 AND RN <= %2").arg(QString::number(index)).arg(QString::number(index+step));

//        return queryModel(model, sql, connName);
//    }

//}
