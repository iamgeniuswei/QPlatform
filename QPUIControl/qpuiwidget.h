#ifndef QPUIWIDGET_H
#define QPUIWIDGET_H

#include <QWidget>
#include "qpuicontrol_global.h"
class QPUIWidgetPrivate;
class QPUICONTROLSHARED_EXPORT QPUIWidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(int xRadius READ xRadius WRITE setXRadius)
    Q_PROPERTY(int yRadius READ yRadius WRITE setYRadius)
    Q_PROPERTY(QColor borderColor READ borderColor WRITE setBorderColor)
    Q_PROPERTY(int widgetMinHeight READ widgetMinHeight WRITE setWidgetMinHeight)
    Q_PROPERTY(int widgetMinWidth READ widgetMinWidth WRITE setWidgetMinWidth)
public:
    explicit QPUIWidget(QWidget *parent = 0);
    virtual ~QPUIWidget();
    virtual void initilizeUI();
    virtual void initilizeSignal();
    virtual void initilizeThread();

signals:

public slots:

public:
    int xRadius() const;
    void setXRadius(const int _xRadius);
    int yRadius() const;
    void setYRadius(const int _yRadius);
    QColor borderColor() const;
    void setBorderColor(const QColor& _borderColor);
    int widgetMinHeight() const;
    void setWidgetMinHeight(const int _widgetHeight);
    int widgetMinWidth() const;
    void setWidgetMinWidth(const int _widgetWidth);


protected:
    virtual void paintEvent(QPaintEvent *);
//    virtual QSize sizeHint() const;

private:
    QPUIWidgetPrivate *const d_ptr;
    Q_DECLARE_PRIVATE(QPUIWidget)
};

#endif // QPUIWIDGET_H
