#ifndef QPDATAOPERATION_P_H
#define QPDATAOPERATION_P_H
#include <QObject>
class QPDataOperation;
class QPDataOperationPrivate
{
    Q_DECLARE_PUBLIC(QPDataOperation)
public:
    QPDataOperationPrivate(QPDataOperation *parent)
        :q_ptr(parent)
    {}
public:
    QString _tableName;
private:
    QPDataOperation *const q_ptr;
};
#endif // QPDATAOPERATION_P_H
