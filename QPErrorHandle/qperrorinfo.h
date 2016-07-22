#ifndef ERRORINFO_H
#define ERRORINFO_H
#include "errorhandle_global.h"
#include <QString>
class QPErrorInfoPrivate;
class ERRORHANDLESHARED_EXPORT QPErrorInfo
{
public:
   explicit QPErrorInfo();
   explicit QPErrorInfo(const int errNo, const QString &errorMsg);
    ~QPErrorInfo();


   int errorNo() const;
   void setErrorNo(const int errorNo);

   QString errorMsg() const;
   void setErrorMsg(const QString &errorMsg);

private:
    QPErrorInfoPrivate * d_ptr;

};

#endif // ERRORINFO_H
