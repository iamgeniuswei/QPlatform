#ifndef QPUIWINDOW_H
#define QPUIWINDOW_H

#include "qpuiwidget.h"
#include "qpuicontrol_global.h"
class QPUIWindowPrivate;
class QPUITitleBar;
class QPUINavigationBar;
class QPUIStatusBar;
class QPUICONTROLSHARED_EXPORT QPUIWindow : public QPUIWidget
{
    Q_OBJECT
public:
    explicit QPUIWindow(QWidget *parent = 0);
    void addTitle(QPUITitleBar *title);
    void addNavigationBar(QPUINavigationBar *navigationBar);
    void addContentArea(QWidget *contentArea);
    void addStatusBar(QPUIStatusBar *statusBar);
    void initilizeUI();

signals:

public slots:
private:
    QPUIWindowPrivate *const d_ptr;
    Q_DECLARE_PRIVATE(QPUIWindow)
};

#endif // QPUIWINDOW_H
