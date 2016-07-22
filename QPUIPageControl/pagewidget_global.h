#ifndef PAGEWIDGET_GLOBAL_H
#define PAGEWIDGET_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(QPUIPageControl_LIBRARY)
#  define PAGEWIDGETSHARED_EXPORT Q_DECL_EXPORT
#else
#  define PAGEWIDGETSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // PAGEWIDGET_GLOBAL_H
