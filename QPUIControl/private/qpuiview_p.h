#ifndef QPUIVIEW_P
#define QPUIVIEW_P
#include <QObject>
class QPUIView;
class QGridLayout;
class QPUIViewPrivate
{
    Q_DECLARE_PUBLIC(QPUIView)
public:
    QPUIViewPrivate(QPUIView *parent = nullptr):q_ptr(parent), mainLayout(nullptr)
    {}

    void init();
    QGridLayout *mainLayout;

private:
    QPUIView *const q_ptr;
};
#endif // QPUIVIEW_P

