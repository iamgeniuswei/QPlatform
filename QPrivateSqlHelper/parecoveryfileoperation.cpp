#include "parecoveryfileoperation.h"

PARecoveryFileOperation::PARecoveryFileOperation(QObject *parent) :
    QPOCIDataOperation(parent)
{
    setTableName("T_VIEW_RECOVERYFILE");
}
