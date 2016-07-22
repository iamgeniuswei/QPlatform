#ifndef QPMESSAGEBOX_P
#define QPMESSAGEBOX_P
#include <QObject>
class QPMessageBoxArea;
class QLabel;
class QPushButton;
class QGridLayout;
class QPMessageBoxAreaPrivate
{
public:
    QPMessageBoxAreaPrivate(QPMessageBoxArea *parent)
        :q_ptr(parent), mainLayout(nullptr), iconLabel(nullptr), informativeLabel(nullptr), okBtn(nullptr), cancelBtn(nullptr)
    {}
    void init();
    void initLayout();
    void initIconLabel();
    void initInformativeLabel();
    void initOkBtn();
    void initCancelBtn();
public:
    QGridLayout *mainLayout;
    QLabel *iconLabel;
    QLabel *informativeLabel;
    QPushButton *okBtn;
    QPushButton *cancelBtn;

private:
    QPMessageBoxArea *const q_ptr;
};

#endif // QPMESSAGEBOX_P

