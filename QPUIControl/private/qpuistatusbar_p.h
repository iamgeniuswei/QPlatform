#ifndef QPUISTATUSBAR_P
#define QPUISTATUSBAR_P
#include <QObject>
class QPUIStatusBar;
class QLabel;
class QGridLayout;
class QPUIStatusBarPrivate
{
    Q_DECLARE_PUBLIC(QPUIStatusBar)
public:
    QPUIStatusBarPrivate(QPUIStatusBar *parent)
        :q_ptr(parent), mainLayout(nullptr), versionLabel(nullptr),logoLabel(nullptr)
    {}
    void init();
public:
    QGridLayout *mainLayout;
    QLabel *versionLabel;
    QLabel *logoLabel;

private:
    QPUIStatusBar *const q_ptr;
};
#endif // QPUISTATUSBAR_P

