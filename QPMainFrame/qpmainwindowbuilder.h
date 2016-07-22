#ifndef QPMAINWINDOWBUILDER_H
#define QPMAINWINDOWBUILDER_H

#include "qpuiwindowbuilder.h"
#include "qpmainframe_global.h"
class QPMainWindowBuilderPrivate;
class QPMAINFRAMESHARED_EXPORT QPMainWindowBuilder : public QPUIWindowBuilder
{
    Q_OBJECT
public:
    explicit QPMainWindowBuilder(QObject *parent = 0);
    void buildTitle();
    void buildNavigationBar();
    void buildContentArea();
    void buildStatusBar();
    QPUIWindow* getWindowInstance();


signals:

public slots:
private:
    QPMainWindowBuilderPrivate *const d_ptr;
    Q_DECLARE_PRIVATE(QPMainWindowBuilder)
};

#endif // QPMAINWINDOWBUILDER_H
