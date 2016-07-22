#ifndef QPUISTATICALLABEL_H
#define QPUISTATICALLABEL_H

#include "qpuiview.h"
#include "qpuicontrol_global.h"
class QPUIStaticalLabelPrivate;
class QPUICONTROLSHARED_EXPORT QPUIStaticalLabel : public QPUIView
{
    Q_OBJECT
public:
    explicit QPUIStaticalLabel(QWidget *parent = 0);
    void initilizeUI();

signals:
    void staticalValueChanged(const int value);
    void clicked();

public slots:
    void setStaticalValue(const int value);
    void setStaticalType(const QString& type);
private slots:
    void setStaticalData(const int value);

protected:
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);

private:
    Q_DECLARE_PRIVATE(QPUIStaticalLabel)
};

#endif // QPUISTATICALLABEL_H
