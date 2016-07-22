#ifndef QPUITITLE_P
#define QPUITITLE_P
#include <QObject>
class QPUITitle;
class QGridLayout;
class QHBoxLayout;
class QLabel;
class QPushButton;

class QPUITitlePrivate
{
    Q_DECLARE_PUBLIC(QPUITitle)
public:
    QPUITitlePrivate(QPUITitle *parent)
        :q_ptr(parent),mainLayout(nullptr), userBtnLayout(nullptr),sysBtnLayout(nullptr),
          mousePress(false), windowMove(true), parentWindow(nullptr)
    {}
    void init();
private:
    //widget elements
    QGridLayout *mainLayout;
    QHBoxLayout *userBtnLayout;
    QHBoxLayout *sysBtnLayout;

    //drag event
    QPoint moveDistance;
    volatile bool mousePress;
    volatile bool windowMove;
    QWidget *parentWindow;


private:
    QPUITitle *const q_ptr;
};


#endif // QPUITITLE_P

