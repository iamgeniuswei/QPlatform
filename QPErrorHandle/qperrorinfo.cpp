#include "qperrorinfo.h"
#include "private/qperrorinfo_p.h"
QPErrorInfo::QPErrorInfo()
    :d_ptr(new (std::nothrow) QPErrorInfoPrivate)
{
}

QPErrorInfo::QPErrorInfo(int errNo, const QString &errorMsg):d_ptr(new (std::nothrow) QPErrorInfoPrivate)
{
    if(d_ptr)
    {
        d_ptr->_errorNo = errNo;
        d_ptr->_errorMsg = errorMsg;
    }
}

QPErrorInfo::~QPErrorInfo()
{
    delete d_ptr;
    d_ptr = nullptr;
}

int QPErrorInfo::errorNo() const
{
    if(d_ptr)
        return d_ptr->_errorNo;
    return 0;
}

void QPErrorInfo::setErrorNo(const int errorNo)
{
    if(d_ptr)
        d_ptr->_errorNo = errorNo;
}
QString QPErrorInfo::errorMsg() const
{
    if(d_ptr)
        return d_ptr->_errorMsg;
    else
        return QString();
}

void QPErrorInfo::setErrorMsg(const QString &errorMsg)
{
    if(d_ptr)
        d_ptr->_errorMsg = errorMsg;
}
