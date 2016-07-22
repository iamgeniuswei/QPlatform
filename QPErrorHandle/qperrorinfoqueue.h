#ifndef ERRORINFOQUEUE_H
#define ERRORINFOQUEUE_H
#include <QString>
#include <QQueue>
#include <QDebug>
#include <QMutex>
#include "errorhandle_global.h"
class QPErrorInfo;
class QPErrorInfoQueuePrivate;
class ERRORHANDLESHARED_EXPORT QPErrorInfoQueue
{
private:
    QPErrorInfoQueue();
    QPErrorInfoQueue(const QPErrorInfoQueue&);
    QPErrorInfoQueue& operator =(const QPErrorInfoQueue&);
    static QPErrorInfoQueue *_instance;

    class GarbageCollection
    {
    public:
        ~GarbageCollection()
        {
            if(_instance != nullptr)
            {
                qDebug() << "test";
                delete _instance;
                _instance = nullptr;
            }
        }
    };

    static GarbageCollection gc;
    static QMutex mutex;



public:
    static QPErrorInfoQueue *getInstance();
public:
   void addErrorInfo(const QPErrorInfo &value);
   void addErrorInfo(const int errNo, const QString& errMsg);
   void cleanErrorInfoQueue();
   QPErrorInfo getLastError();

private:
   QPErrorInfoQueuePrivate *const d_ptr;
   Q_DECLARE_PRIVATE(QPErrorInfoQueue)
};

#endif // ERRORINFOQUEUE_H
