#ifndef QPCHARTS_GLOBAL_H
#define QPCHARTS_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(QPCHARTS_LIBRARY)
#  define QPCHARTSSHARED_EXPORT Q_DECL_EXPORT
#else
#  define QPCHARTSSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // QPCHARTS_GLOBAL_H
