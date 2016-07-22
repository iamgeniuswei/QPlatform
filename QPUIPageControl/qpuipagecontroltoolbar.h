#ifndef DATAOPERATIONWIDGET_H
#define DATAOPERATIONWIDGET_H
//#include "qpwidget.h"
#include "pagewidget_global.h"
#include "qpuiwidget.h"
class QPUIPageControlToolBarPrivate;
class PAGEWIDGETSHARED_EXPORT QPUIPageControlToolBar : public QPUIWidget
{
    Q_OBJECT
public:
    explicit QPUIPageControlToolBar(QWidget *parent = 0);
    void initilizeUI();
    void initilizeSignal();

signals:
    void showPrevPage();
    void showNextPage();
    void showFirstPage();
    void showLastPage();
    void switchPageTo(int page);
public slots:
    void updateTotalRecord(int page, int record);
    void updateCurrentRecord(int start, int end);
    void updateBtnStatus(int index);
    void switchPage();

private:
    QPUIPageControlToolBarPrivate *const d_ptr;
    Q_DECLARE_PRIVATE(QPUIPageControlToolBar)

};

#endif // DATAOPERATIONWIDGET_H
