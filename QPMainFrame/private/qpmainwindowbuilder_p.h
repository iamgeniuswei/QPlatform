#ifndef QPMAINWINDOWBUILDER_P
#define QPMAINWINDOWBUILDER_P
#include <QObject>
class QPMainWindowBuilder;
class QPUIWindow;
class QPMainWindowBuilderPrivate
{
public:
    QPMainWindowBuilderPrivate() {}
public:
    void init();
    QPUIWindow *mainWindow;
};
#endif // QPMAINWINDOWBUILDER_P

