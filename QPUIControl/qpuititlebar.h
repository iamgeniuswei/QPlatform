#ifndef QPUITITLE_H
#define QPUITITLE_H

#include "qpuiwidget.h"
#include "qpuicontrol_global.h"
class QLabel;
class QPushButton;
class QPUITitleBarPrivate;
class QPUICONTROLSHARED_EXPORT QPUITitleBar : public QPUIWidget
{
    Q_OBJECT
public:
    explicit QPUITitleBar(QWidget *parent = 0);
    void addTitleLogo(QLabel *logo);
    void addTitleText(QWidget *text);
    void addSubTitleText(QLabel *text);
    void addSysBtn(QPushButton *sysBtn);
    void addCustomBtn(QWidget *customBtn);
    void setParent(QWidget *parent);
    void initilizeUI();

protected:
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
signals:

public slots:

private:
    QPUITitleBarPrivate *const d_ptr;
    Q_DECLARE_PRIVATE(QPUITitleBar)
};

#endif // QPUITITLE_H
