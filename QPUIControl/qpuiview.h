#ifndef QPUIVIEW_H
#define QPUIVIEW_H

#include "qpuiwidget.h"
#include "qpuicontrol_global.h"
class QPUIViewPrivate;
class QGridLayout;
class QPUICONTROLSHARED_EXPORT QPUIView : public QPUIWidget
{
    Q_OBJECT
public:
    explicit QPUIView(QWidget *parent = 0);
    void initilizeUI();
    void addWidget(QWidget *widget, int row, int column, int rowSpan, int columnSpan, Qt::Alignment align = 0);
    QGridLayout *getLayout() const;
signals:

public slots:

protected:
    explicit QPUIView(QPUIViewPrivate *dd, QWidget *parent = 0);
    QPUIViewPrivate *const d_ptr;
    Q_DECLARE_PRIVATE(QPUIView)
};

#endif // QPUIVIEW_H
