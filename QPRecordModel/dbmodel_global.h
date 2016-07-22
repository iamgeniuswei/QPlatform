#ifndef DBMODEL_GLOBAL_H
#define DBMODEL_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(DBMODEL_LIBRARY)
#  define DBMODELSHARED_EXPORT Q_DECL_EXPORT
#else
#  define DBMODELSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // DBMODEL_GLOBAL_H
