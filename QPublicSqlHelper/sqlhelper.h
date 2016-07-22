#ifndef SQLHELPER_H
#define SQLHELPER_H

#include "sqlhelper_global.h"
#include "qpsqlworkthread.h"
#include "qpquerythread.h"
#include "sqlobjectfactory.h"
//#include "qocitaskoperation.h"
//#include "qociresultoperation.h"
//#include "qocilogoperation.h"
//#include "qocilogviewoperation.h"
//#include "pataskinfooperation.h"
//#include "paonlinepcapoperation.h"
//#include "paofflinepcapoperation.h"
//#include "paflowoperation.h"
//#include "papktsizeoperation.h"
//#include "papktinfooperation.h"
//#include "paaddressoperation.h"
//#include "paprotooperation.h"
//#include "paphysicalsessionoperation.h"
//#include "paipv4sessionoperataion.h"
//#include "paipv6sessionoperation.h"
//#include "patcpsessionoperation.h"
//#include "paudpsessionoperation.h"
//#include "paonlinefileoperation.h"
//#include "paofflinefileoperation.h"
//#include "pataskinfoqpquerymodel.h"
//#include "paflowqpquerymodel.h"
//#include "papktsizeqpquerymodel.h"
//#include "paphysicalsessionqpquerymodel.h"
//#include "paipv4sessionqpquerymodel.h"
//#include "paipv6sessionqpquerymodel.h"
//#include "patcpsessionqpquerymodel.h"
//#include "paudpsessionqpquerymodel.h"
//#include "onlinefilequeymodel.h"
#include "qpnonquerythread.h"
//#include "qocitaskviewoperation.h"
//#include "qociresultviewoperation.h"
//#include "qociuseroperation.h"
//#include "paaddressqpquerymodel.h"
//#include "paprotoqpquerymodel.h"
//#include "qocistatustypeoperation.h"
//#include "qociresultoperation.h"
class SQLHELPEREXPORT SqlHelper
{

public:
    SqlHelper();
    static QString getTaskConnection()
    {
        QString connName = "TaskDB";
        return connName;
    }
    static QPSqlWorkThread* createQueryThread()
    {
        return new (std::nothrow) QPQueryThread;
    }
    static QPSqlWorkThread *createNonQueryThrad()
    {
        return new (std::nothrow) QPNonQueryThread;
    }

//    static void createObject()
//    {
//        SqlObjectFactory *factory = new SqlObjectFactory;
//        factory->registerObject<QOCITaskOperation>();
//        factory->registerObject<QOCIUserOperation>();
//        factory->registerObject<QOCIResultOperation>();
//        factory->registerObject<QOCILogOperation>();
//        factory->registerObject<QOCILogViewOperation>();
//        factory->registerObject<QOCITaskViewOperation>();
//        factory->registerObject<QOCIResultViewOperation>();
//        factory->registerObject<QOCIStatusTypeOperation>();
//        factory->registerObject<QOCIResultOperation>();
//        factory->registerObject<PATaskInfoOperation>();
//        factory->registerObject<PAOnlinePcapOperation>();
//        factory->registerObject<PAOfflinePcapOperation>();
//        factory->registerObject<PAFlowOperation>();
//        factory->registerObject<PAPktSizeOperation>();
//        factory->registerObject<PAAddressOperation>();
//        factory->registerObject<PAProtoOperation>();
//        factory->registerObject<PAPhysicalSessionOperation>();
//        factory->registerObject<PAIPV4SessionOperation>();
//        factory->registerObject<PAIPV6SessionOperation>();
//        factory->registerObject<PATCPSessionOperation>();
//        factory->registerObject<PAUDPSessionOperation>();
//        factory->registerObject<PAPktInfoOperation>();
//        factory->registerObject<PAOnlineFileOperation>();
//        factory->registerObject<PAOfflineFileOperation>();
//    }
//    static void createModelObject()
//    {
//        SqlObjectFactory *modelFactory = new SqlObjectFactory;
//        modelFactory->registerModelObject<QMySqlFileQueryModel>();
//        modelFactory->registerModelObject<PATaskInfoQueryModel>();
//        modelFactory->registerModelObject<PAFlowQueryModel>();
//        modelFactory->registerModelObject<PAPktSizeQueryModel>();
//        modelFactory->registerModelObject<PAPhysicalSessionQueryModel>();
//        modelFactory->registerModelObject<PAIPV4SessionQueryModel>();
//        modelFactory->registerModelObject<PAIPV6SessionQueryModel>();
//        modelFactory->registerModelObject<PATCPSessionQueryModel>();
//        modelFactory->registerModelObject<PAUDPSessionQueryModel>();
//        modelFactory->registerModelObject<PAAddressQueryModel>();
//        modelFactory->registerModelObject<PAProtoQueryModel>();
//    }
};

#endif // SQLHELPER_H
