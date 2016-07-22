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

void QPErrorInfoQueue::addErrorInfo(const QPErrorInfo &value)
{
    Q_D(QPErrorInfoQueue);
    d->_errorInfoQueue.push(value);
}

void QPErrorInfoQueue::addErrorInfo(const int errNo, const QString &errMsg)
{    
    Q_D(QPErrorInfoQueue);
    mutex.lock();
    QPErrorInfo info(errNo, errMsg);
    d->_errorInfoQueue.push(info);
    mutex.unlock();
}

void QPErrorInfoQueue::cleanErrorInfoQueue()
{
    Q_D(QPErrorInfoQueue);
    d->_errorInfoQueue.clear();
}

QPErrorInfo QPErrorInfoQueue::getLastError()
{
    Q_D(QPErrorInfoQueue);
    QPErrorInfo error;
    if(d->_errorInfoQueue.isEmpty())
        return error;
    error = d->_errorInfoQueue.pop();
    return error;
}
