#include "qocitaskviewoperation.h"

QOCITaskViewOperation::QOCITaskViewOperation(QObject *parent)
    :QPOCIDataOperation(parent)
{
    setTableName("VIEW_TASK");
}

int QOCITaskViewOperation::InsertRecord(DBModel *)
{
    return 0;
}

int QOCITaskViewOperation::DeleteRecord(DBModel *)
{
    return 0;
}

int QOCITaskViewOperation::UpdateRecord(DBModel *)
{
    return 0;
}

DBModel *QOCITaskViewOperation::QueryRecord(int)
{
    return NULL;
}

DBModel *QOCITaskViewOperation::QueryByOrigin(int)
{
    return 0;
}
