#ifndef QPSIPTEST_GLOBAL_H
#define QPSIPTEST_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(QPSIPTEST_LIBRARY)
#  define QPSIPTESTSHARED_EXPORT Q_DECL_EXPORT
#else
#  define QPSIPTESTSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // QPSIPTEST_GLOBAL_H
