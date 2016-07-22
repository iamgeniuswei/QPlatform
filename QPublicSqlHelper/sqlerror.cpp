#include "sqlerror.h"
const QString SqlError::errStr_PointIsNull = tr("zhizhenweikong");
const QString SqlError::errStr_SqlIsEmpty = tr("sqlyujuweikong");
const QString SqlError::errStr_TableIsNull = tr("tableweikong");
const QString SqlError::errStr_ObjectIsNull = tr("duixiangchuangjianshibai");
SqlError::SqlError(QObject *parent):
    QObject(parent)
{

}
