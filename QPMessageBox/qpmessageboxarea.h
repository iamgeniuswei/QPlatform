#ifndef QPMESSAGEBOXAREA_H
#define QPMESSAGEBOXAREA_H

#include "qpmessagebox_global.h"
#include "qpuiwidget.h"
class QPMessageBoxAreaPrivate;
class QPMESSAGEBOXSHARED_EXPORT QPMessageBoxArea : QPUIWidget
{
    Q_OBJECT
public:
    explicit QPMessageBoxArea(QWidget *parent = 0);
    void initilizeUI();
    enum Icon{
        NoIcon,Information,Warning,Critical,Question
    };
    Q_ENUM(Icon)
    void setInformativeText(const QString &text);
    void setIcon(Icon type);

private:
    QPMessageBoxAreaPrivate *const d_ptr;
    Q_DECLARE_PRIVATE(QPMessageBoxArea)
};

#endif // QPMESSAGEBOXAREA_H
