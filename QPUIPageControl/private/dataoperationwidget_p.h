#ifndef DATAOPERATIONWIDGET_P_H
#define DATAOPERATIONWIDGET_P_H
#include <QObject>
class QPUIPageControlToolBar;
class QPDynamicIconButton;
class QLabel;
class QLineEdit;
class QHBoxLayout;
class QPushButton;
class QGridLayout;
class QPUIPageControlToolBarPrivate
{
    Q_DECLARE_PUBLIC(QPUIPageControlToolBar)
public:
    QPUIPageControlToolBarPrivate(QPUIPageControlToolBar *parent = 0)
        : mainLayout(nullptr),\
          firstBtn(nullptr), \
          prevBtn(nullptr),\
          nextBtn(nullptr),\
          lastBtn(nullptr),\
          switchPageLE(nullptr),
          totalPageLb(nullptr),\
          currentRecordLb(nullptr),
          totalRecordLb(nullptr),
          q_ptr(parent),\
          _totalPage(0),\
          _totalRecord(0),\
          _startRecord(0),
          _endRecord(0)
    {}
    ~QPUIPageControlToolBarPrivate();
    void init();
public:
    QHBoxLayout *mainLayout;
    QPushButton *firstBtn;
    QPushButton *prevBtn;
    QPushButton *nextBtn;
    QPushButton *lastBtn;
    QLineEdit *switchPageLE;
    QLabel *totalPageLb;
    QLabel *currentRecordLb;
    QLabel *totalRecordLb;

    QString totalPageStr;
    QString currentRecordStr;
    QString totalRecordStr;

    //data member
    int _totalPage;
    int _totalRecord;
    int _startRecord;
    int _endRecord;

private:
    QPUIPageControlToolBar *const q_ptr;
};


#endif // DATAOPERATIONWIDGET_P_H
