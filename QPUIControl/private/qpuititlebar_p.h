#ifndef QPUITITLE_P
#define QPUITITLE_P
#include <QObject>
#include <QPointer>
class QPUITitleBar;
class QGridLayout;
class QHBoxLayout;
class QPUITitleBarPrivate
{
    Q_DECLARE_PUBLIC(QPUITitleBar)
public:
    QPUITitleBarPrivate(QPUITitleBar *parent)
        :q_ptr(parent),mousePress(false), windowMove(true)
    {}
    void init();
private:
    //widget elements
    QPointer<QGridLayout> mainLayout;
    QPointer<QHBoxLayout> customLayout;
    QPointer<QHBoxLayout> systemLayout;
    QPointer<QWidget> parentWindow;

    //drag event
    QPoint moveDistance;
    volatile bool mousePress;
    volatile bool windowMove;

private:
    QPUITitleBar *const q_ptr;
};


#endif // QPUITITLE_P

