#ifndef SQLHELPER_GLOBAL_H
#define SQLHELPER_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SQLHELPER_LIBRARY)
#  define SQLHELPEREXPORT Q_DECL_EXPORT
#else
#  define SQLHELPEREXPORT Q_DECL_IMPORT
#endif

#endif // SQLHELPER_GLOBAL_H
