#ifndef QPUITITLE_H
#define QPUITITLE_H

#include "qpuiwidget.h"
#include "qpuicontrol_global.h"
class QLabel;
class QPushButton;
class QPUITitlePrivate;
class QPUICONTROLSHARED_EXPORT QPUITitle : public QPUIWidget
{
    Q_OBJECT
public:
    explicit QPUITitle(QWidget *parent = 0);
    void addTitleLogo(QLabel *logo);
    void addTitleText(QWidget *text);
    void addSubTitleText(QLabel *text);
    void addSysBtn(QPushButton *sysBtn);
    void addUserBtn(QWidget *userBtn);
    void setParent(QWidget *parent);
    void initilizeUI();

protected:
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
signals:

public slots:

private:
    QPUITitlePrivate *const d_ptr;
    Q_DECLARE_PRIVATE(QPUITitle)
};

#endif // QPUITITLE_H
