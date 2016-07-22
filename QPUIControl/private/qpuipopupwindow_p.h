#ifndef QPUIPOPUPWINDOW_P
#define QPUIPOPUPWINDOW_P
#include <QObject>
class QPUIPopupWindow;
class QVBoxLayout;
class QPUITitle;
class QWidget;
class QPUIWidget;
class QPUIPopupWindowPrivate
{
public:
    QPUIPopupWindowPrivate(QPUIPopupWindow *parent)
        :q_ptr(parent), mainLayout(nullptr), title(nullptr), contentArea(nullptr)
    {}
    void init();
public:
    QVBoxLayout *mainLayout;
    QPUITitle *title;
    QPUIWidget *contentArea;
    QVBoxLayout *contentLayout;

private:
    QPUIPopupWindow *const q_ptr;


};
#endif // QPUIPOPUPWINDOW_P

