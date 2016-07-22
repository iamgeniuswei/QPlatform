#ifndef QPMESSAGEBOXBUILDER_H
#define QPMESSAGEBOXBUILDER_H

#include "qpuipopupwindowbuilder.h"
class QPUIPopupWindow;
class QPMessageBoxBuilder : public QPUIPopupWindowBuilder
{
    Q_OBJECT
public:
    explicit QPMessageBoxBuilder(QObject *parent = 0);
    void buildTitle();
    void buildContentArea();
    QPUIPopupWindow *getPopupWindow();

signals:

public slots:
};

#endif // QPMESSAGEBOXBUILDER_H
