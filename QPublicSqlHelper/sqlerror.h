#ifndef SQLERROR_H
#define SQLERROR_H
#include <QSqlError>
#include <QObject>
#include "errorhandle.h"
#include "sqlhelper_global.h"
class SQLHELPEREXPORT SqlError : public QObject
{
	Q_ENUMS(ERRORCODE)
    Q_ENUMS(RETCODE)
    Q_ENUMS(RETCODEINT)
public:
	SqlError(QObject *parent = 0);
	typedef enum{
        errNo_SqlIsEmpty = 10000,
        errNo_TableIsNULL,
		errNo_ConneciontError,
		errNo_PointIsNULL,
        errNo_ObjectIsNull,
		errNo_ModelQueryError,
		errNo_QueryExecError,
		errNo_ModelInsertError,
		errNo_ModelUpdateError,
        errNo_ModelDeleteError,
        errNo_NoRecord
	}ERRORCODE;

    typedef enum{
        retNO_FAIL = false,
        retNO_SUCCESS = true
    }RETCODE;

    typedef enum{
        retNO_ERROR = -1
    }RETCODEINT;
	static const int retInsertRecordError = -1;
	static const QString errStr_SqlIsEmpty;
	static const QString errStr_PointIsNull;
    static const QString errStr_TableIsNull;
    static const QString errStr_ObjectIsNull;
};
#endif // SQLERROR_H

