#ifndef QPUISTATUSBAR_H
#define QPUISTATUSBAR_H

#include "qpuiwidget.h"
#include "qpuicontrol_global.h"
class QPUIStatusBarPrivate;
class QPUICONTROLSHARED_EXPORT QPUIStatusBar : public QPUIWidget
{
    Q_OBJECT
public:
    explicit QPUIStatusBar(QWidget *parent = 0);
    void initilizeUI();
protected:
//    void paintEvent(QPaintEvent *);
signals:

public slots:
private:
    QPUIStatusBarPrivate *const d_ptr;
    Q_DECLARE_PRIVATE(QPUIStatusBar)
};

#endif // QPUISTATUSBAR_H
