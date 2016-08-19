#ifndef QPUIPOPUPWINDOW_H
#define QPUIPOPUPWINDOW_H

#include "qpuiwidget.h"
#include "qpuicontrol_global.h"
class QPUITitleBar;
class QLabel;
class QPUIPopupWindowPrivate;

class QPUICONTROLSHARED_EXPORT QPUIPopupWindow : public QPUIWidget
{
    Q_OBJECT
public:
    explicit QPUIPopupWindow(QWidget *parent = 0);
    void addTitle(QPUITitleBar *title);
    void addContentArea(QPUIWidget *contentArea);
    void initilizeUI();

    QPUITitleBar *getTitle() const;

    void setTitleLogo(QLabel *logo);
    void setTitleWidget(QWidget *widget);



signals:

public slots:    

protected:
    explicit QPUIPopupWindow(QPUIPopupWindowPrivate *dd, QWidget *parent = 0);
    QPUIPopupWindowPrivate *const d_ptr;
    Q_DECLARE_PRIVATE(QPUIPopupWindow)
};

#endif // QPUIPOPUPWINDOW_H
