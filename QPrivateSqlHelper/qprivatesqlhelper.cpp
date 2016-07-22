#include "qprivatesqlhelper.h"
#include "sqlobjectfactory.h"
#include "qocitaskoperation.h"
#include "qociresultoperation.h"
#include "qocilogoperation.h"
#include "qocilogviewoperation.h"
#include "pataskinfooperation.h"
#include "paonlinepcapoperation.h"
#include "paofflinepcapoperation.h"
#include "paflowoperation.h"
#include "papktsizeoperation.h"
#include "papktinfooperation.h"
#include "paaddressoperation.h"
#include "paprotooperation.h"
#include "paphysicalsessionoperation.h"
#include "paipv4sessionoperataion.h"
#include "paipv6sessionoperation.h"
#include "patcpsessionoperation.h"
#include "paudpsessionoperation.h"
#include "paonlinefileoperation.h"
#include "paofflinefileoperation.h"
#include "pataskinfoquerymodel.h"
#include "paflowquerymodel.h"
#include "papktsizequerymodel.h"
#include "paphysicalsessionquerymodel.h"
#include "paipv4sessionquerymodel.h"
#include "paipv6sessionquerymodel.h"
#include "patcpsessionquerymodel.h"
#include "paudpsessionquerymodel.h"
#include "onlinefilequeymodel.h"
//#include "qpnonquerythread.h"
#include "qocitaskviewoperation.h"
#include "qociresultviewoperation.h"
#include "qociuseroperation.h"
#include "paaddressquerymodel.h"
#include "paprotoquerymodel.h"
#include "qocistatustypeoperation.h"
#include "qociresultoperation.h"
#include "paofflinefilequerymodel.h"
#include "paonlinepcapquerymodel.h"
#include "qocisoftwarestatus.h"
#include "qociuserstatusoperation.h"
#include "parecoveryfileoperation.h"
#include "qocitaskstatusoperation.h"

QPrivateSqlHelper::QPrivateSqlHelper()
{
}

void QPrivateSqlHelper::createObject()
{
    SqlObjectFactory *factory = new SqlObjectFactory;
    factory->registerObject<QOCITaskOperation>();
    factory->registerObject<QOCIUserOperation>();
    factory->registerObject<QOCIResultOperation>();
    factory->registerObject<QOCILogOperation>();
    factory->registerObject<QOCILogViewOperation>();
    factory->registerObject<QOCITaskViewOperation>();
    factory->registerObject<QOCIResultViewOperation>();
    factory->registerObject<QOCIStatusTypeOperation>();
    factory->registerObject<QOCIResultOperation>();
    factory->registerObject<QOCISoftwareStatusOperation>();
    factory->registerObject<QOCIUserStatusOperation>();
    factory->registerObject<QOCITaskStatusOperation>();
    factory->registerObject<PATaskInfoOperation>();
    factory->registerObject<PAOnlinePcapOperation>();
    factory->registerObject<PAOfflinePcapOperation>();
    factory->registerObject<PAFlowOperation>();
    factory->registerObject<PAPktSizeOperation>();
    factory->registerObject<PAAddressOperation>();
    factory->registerObject<PAProtoOperation>();
    factory->registerObject<PAPhysicalSessionOperation>();
    factory->registerObject<PAIPV4SessionOperation>();
    factory->registerObject<PAIPV6SessionOperation>();
    factory->registerObject<PATCPSessionOperation>();
    factory->registerObject<PAUDPSessionOperation>();
    factory->registerObject<PAPktInfoOperation>();
    factory->registerObject<PAOnlineFileOperation>();
    factory->registerObject<PAOfflineFileOperation>();
    factory->registerObject<PARecoveryFileOperation>();
}

void QPrivateSqlHelper::createModelObject()
{
    SqlObjectFactory *modelFactory = new SqlObjectFactory;
    modelFactory->registerModelObject<PATaskInfoQueryModel>();
    modelFactory->registerModelObject<PAFlowQueryModel>();
    modelFactory->registerModelObject<PAPktSizeQueryModel>();
    modelFactory->registerModelObject<PAPhysicalSessionQueryModel>();
    modelFactory->registerModelObject<PAIPV4SessionQueryModel>();
    modelFactory->registerModelObject<PAIPV6SessionQueryModel>();
    modelFactory->registerModelObject<PATCPSessionQueryModel>();
    modelFactory->registerModelObject<PAUDPSessionQueryModel>();
    modelFactory->registerModelObject<PAAddressQueryModel>();
    modelFactory->registerModelObject<PAProtoQueryModel>();
    modelFactory->registerModelObject<PAOfflineFileQueryModel>();
    modelFactory->registerModelObject<PAOnlinePcapQueryModel>();
}
