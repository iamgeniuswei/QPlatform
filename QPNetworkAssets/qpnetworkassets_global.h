#ifndef QPNETWORKASSETS_GLOBAL_H
#define QPNETWORKASSETS_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(QPNETWORKASSETS_LIBRARY)
#  define QPNETWORKASSETSSHARED_EXPORT Q_DECL_EXPORT
#else
#  define QPNETWORKASSETSSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // QPNETWORKASSETS_GLOBAL_H
