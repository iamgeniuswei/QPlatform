#ifndef QPUIWINDOW_P
#define QPUIWINDOW_P
#include <QObject>
class QPUIWindow;
class QGridLayout;
class QSplitter;
class QPUIWindowPrivate
{
public:
    QPUIWindowPrivate(QPUIWindow *parent)
        :q_ptr(parent), mainLayout(nullptr), mainSplitter(nullptr)
    {}
    void init();
public:
    QGridLayout *mainLayout;
    QSplitter *mainSplitter;

private:
    QPUIWindow *const q_ptr;
};

#endif // QPUIWINDOW_P

