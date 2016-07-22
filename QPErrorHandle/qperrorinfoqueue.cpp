/*
 * Modify Time : 2016-07-22 10:08 +8:00
 * Modify Purpose : Fix addErrorInfo(int,QString) ,
 *                  This function have a bug, when push
 *                  a QErrorInfo to the Stack, may cause
 *                  app to crash.
 * Modify method : Replace local variable with pointer.
 *
 */


#include "qperrorinfoqueue.h"
#include "private/qperrorinfoqueue_p.h"
#include "qperrorinfo.h"

QPErrorInfoQueue *QPErrorInfoQueue::_instance = nullptr;
QPErrorInfoQueue ::GarbageCollection QPErrorInfoQueue::gc;
QMutex QPErrorInfoQueue::mutex;
QPErrorInfoQueue::QPErrorInfoQueue()
    :d_ptr(new QPErrorInfoQueuePrivate(this))
{

}

QPErrorInfoQueue::~QPErrorInfoQueue()
{
    cleanErrorInfoQueue();
}

QPErrorInfoQueue *QPErrorInfoQueue::getInstance()
{
    if(_instance == nullptr)
    {
        mutex.lock();
        if(_instance == nullptr)
            _instance = new (std::nothrow) QPErrorInfoQueue;
        mutex.unlock();
    }
    return _instance;
}

void QPErrorInfoQueue::addErrorInfo(QPErrorInfo *value)
{
    Q_D(QPErrorInfoQueue);
    d->_errorInfoQueue.push(value);
}

void QPErrorInfoQueue::addErrorInfo(int errNo, const QString &errMsg)
{    
    Q_D(QPErrorInfoQueue);
    mutex.lock();
    QPErrorInfo *info = new QPErrorInfo(errNo, errMsg);
    d->_errorInfoQueue.push(info);
    mutex.unlock();
}

void QPErrorInfoQueue::cleanErrorInfoQueue()
{
    Q_D(QPErrorInfoQueue);
    while (!d->_errorInfoQueue.isEmpty()) {
        QPErrorInfo* error = d->_errorInfoQueue.pop();
        delete error;
    }
}

QPErrorInfo* QPErrorInfoQueue::getLastError()
{
    Q_D(QPErrorInfoQueue);
    if(d->_errorInfoQueue.isEmpty())
        return nullptr;
    QPErrorInfo* error = d->_errorInfoQueue.pop();
    return error;
}

int QPErrorInfoQueue::getErrorCount() const
{
    Q_D(const QPErrorInfoQueue);
    return d->_errorInfoQueue.size();
}
