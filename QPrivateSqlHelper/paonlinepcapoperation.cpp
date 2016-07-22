#include "paonlinepcapoperation.h"

PAOnlinePcapOperation::PAOnlinePcapOperation(QObject *parent)
    :QPOCIDataOperation(parent)
{
    setTableName("T_VIEW_PCAPFILE_ONLINE");
}
