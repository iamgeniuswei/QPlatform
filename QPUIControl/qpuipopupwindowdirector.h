#ifndef QPUIPOPUPWINDOWDIRECTOR_H
#define QPUIPOPUPWINDOWDIRECTOR_H

#include <QObject>
class QPUIPopupWindowBuilder;
class QPUIPopupWindowDirector : public QObject
{
    Q_OBJECT
public:
    explicit QPUIPopupWindowDirector(QObject *parent = 0);
    void buildPopupWindow(QPUIPopupWindowBuilder *_builder);

signals:

public slots:
};

#endif // QPUIPOPUPWINDOWDIRECTOR_H
