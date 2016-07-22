#ifndef QPMAINWINDOW_GLOBAL_H
#define QPMAINWINDOW_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(QPMAINWINDOW_LIBRARY)
#  define QPMAINWINDOWSHARED_EXPORT Q_DECL_EXPORT
#else
#  define QPMAINWINDOWSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // QPMAINWINDOW_GLOBAL_H
