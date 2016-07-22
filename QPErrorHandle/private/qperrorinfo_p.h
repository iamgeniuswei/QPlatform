#ifndef QPERRORINFO_P_H
#define QPERRORINFO_P_H
#include <QObject>
class QPErrorInfo;
class QPErrorInfoPrivate
{
public:
    QPErrorInfoPrivate()
        :_errorNo(0)
    {}
private:
    int _errorNo;
    QString _errorMsg;

    friend class QPErrorInfo;

};
#endif // QPERRORINFO_P_H
