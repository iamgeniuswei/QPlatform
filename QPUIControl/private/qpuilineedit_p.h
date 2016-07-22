#ifndef QPUILINEEDIT_P
#define QPUILINEEDIT_P
#include <QObject>
#include <QRegExp>
class QPUILineEdit;
class QPUILineEditPrivate
{
public:
    QPUILineEditPrivate()
        : regExp(nullptr)
    {}

    QRegExp *regExp;
};

#endif // QPUILINEEDIT_P

