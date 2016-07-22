#ifndef QPMESSAGEBOX_P
#define QPMESSAGEBOX_P
#include "private/qpuipopupwindow_p.h"
class QPMessageBox;
class QPUITitle;
class QPMessageBoxArea;
class QPMessageBoxPrivate : public QPUIPopupWindowPrivate
{
public:
    QPMessageBoxPrivate(QPMessageBox *parent):
        q_ptr(parent),QPUIPopupWindowPrivate(parent),
        title(nullptr), area(nullptr)
    {
    }
    void init();
public:
    QPUITitle *title;
    QPMessageBoxArea *area;

private:
     QPMessageBox *const q_ptr;
};

#endif // QPMESSAGEBOX_P

