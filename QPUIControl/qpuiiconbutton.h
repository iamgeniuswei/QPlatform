#ifndef QPUIICONBUTTON_H
#define QPUIICONBUTTON_H

#include <QPushButton>
#include "qpuicontrol_global.h"
class QPUIIconButtonPrivate;
class QPUICONTROLSHARED_EXPORT QPUIIconButton : public QPushButton
{
    Q_OBJECT
    Q_PROPERTY(QString iconPath READ iconPath WRITE setIconPath)
public:
    explicit QPUIIconButton(QWidget *parent = 0);
    enum BUTTONSTATUS{NORMAL, ENTER, LEAVE, PRESS, RELEASE, DISABLE};
    Q_ENUM(BUTTONSTATUS)

    QString iconPath() const;
    void setIconPath(const QString &_iconPath);

protected:
    void setBtnIcon(const QString &_iconPath, int num = 4);
    void setBtnStatus(BUTTONSTATUS _status);
    void paintEvent(QPaintEvent *);
    void enterEvent(QEvent*);
    void leaveEvent(QEvent *);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

signals:

public slots:

private:
    QPUIIconButtonPrivate *const d_ptr;
    Q_DECLARE_PRIVATE(QPUIIconButton)
};

#endif // QPUIICONBUTTON_H
