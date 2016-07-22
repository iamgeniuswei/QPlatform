#include "paofflinepcapoperation.h"

PAOfflinePcapOperation::PAOfflinePcapOperation(QObject *parent)
    :QPOCIDataOperation(parent)
{
    setTableName("T_DATA_PCAPFILE_OFFLINE");
}
