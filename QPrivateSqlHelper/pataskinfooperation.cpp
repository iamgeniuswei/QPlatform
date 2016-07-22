#include "pataskinfooperation.h"

PATaskInfoOperation::PATaskInfoOperation(QObject *parent)
    :QPOCIDataOperation(parent)
{
    setTableName("T_VIEW_TASKINFO");
}
