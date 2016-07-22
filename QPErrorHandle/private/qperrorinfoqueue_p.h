#ifndef QPERRORINFOQUEUE_P_H
#define QPERRORINFOQUEUE_P_H
#include <QObject>
#include <QMutex>
#include <QStack>
class QPErrorInfoQueue;
class QPErrorInfo;
class QPErrorInfoQueuePrivate
{
    Q_DECLARE_PUBLIC(QPErrorInfoQueue)
public:
    QPErrorInfoQueuePrivate(QPErrorInfoQueue *parent)
        :q_ptr(parent)
    {}
public:
    QStack<QPErrorInfo> _errorInfoQueue;
private:
    QPErrorInfoQueue *const q_ptr;
};
#endif // QPERRORINFOQUEUE_P_H
