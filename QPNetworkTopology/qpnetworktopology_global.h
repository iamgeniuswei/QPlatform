#ifndef QPNETWORKTOPOLOGY_GLOBAL_H
#define QPNETWORKTOPOLOGY_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(QPNETWORKTOPOLOGY_LIBRARY)
#  define QPNETWORKTOPOLOGYSHARED_EXPORT Q_DECL_EXPORT
#else
#  define QPNETWORKTOPOLOGYSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // QPNETWORKTOPOLOGY_GLOBAL_H
