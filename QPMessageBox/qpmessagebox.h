#ifndef QPMESSAGEBOX_H
#define QPMESSAGEBOX_H

#include "qpuipopupwindow.h"
#include "qpmessagebox_global.h"
class QPMessageBoxPrivate;
class QPMessageBoxArea;
class QPMESSAGEBOXSHARED_EXPORT QPMessageBox : public QPUIPopupWindow
{
    Q_OBJECT
public:
    explicit QPMessageBox(QWidget *parent = 0);
//    void initilizeUI();
    void setInformativeText(const QString& text);
//    void setIcon(Icon type);

signals:

public slots:
private:
    Q_DECLARE_PRIVATE(QPMessageBox)
};

#endif // QPMESSAGEBOX_H
