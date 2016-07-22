#ifndef QPUIWIDGET_P
#define QPUIWIDGET_P
#include <QObject>
#include <QColor>
class QPUIWidget;
class QPUIWidgetPrivate
{
public:
    QPUIWidgetPrivate():
        xRadius(0), yRadius(0),widgetMinHeight(0),widgetMinWidth(0)
    {}

public:
    int xRadius;
    int yRadius;
    int widgetMinHeight;
    int widgetMinWidth;
    QColor borderColor;
private:

};

#endif // QPUIWIDGET_P

