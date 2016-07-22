#ifndef QPRIVATESQLHELPER_H
#define QPRIVATESQLHELPER_H

#include "qprivatesqlhelper_global.h"

class QPRIVATESQLHELPERSHARED_EXPORT QPrivateSqlHelper
{

public:
    QPrivateSqlHelper();
    static void createObject();
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
    static void createModelObject();
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

#endif // QPRIVATESQLHELPER_H
