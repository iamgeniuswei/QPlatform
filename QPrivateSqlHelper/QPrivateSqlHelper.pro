#-------------------------------------------------
#
# Project created by QtCreator 2015-11-02T14:46:19
#
#-------------------------------------------------

QT       += sql gui

TARGET = QPrivateSqlHelper
TEMPLATE = lib

DEFINES += QPRIVATESQLHELPER_LIBRARY

SOURCES += qprivatesqlhelper.cpp \
    paaddressoperation.cpp \
    paaddressquerymodel.cpp \
    paflowoperation.cpp \
    paflowquerymodel.cpp \
    paipv4sessionoperataion.cpp \
    paipv4sessionquerymodel.cpp \
    paipv6sessionoperation.cpp \
    paipv6sessionquerymodel.cpp \
    paofflinefileoperation.cpp \
    paofflinepcapoperation.cpp \
    paonlinefileoperation.cpp \
    paonlinepcapoperation.cpp \
    paphysicalsessionoperation.cpp \
    paphysicalsessionquerymodel.cpp \
    papktinfooperation.cpp \
    papktsizeoperation.cpp \
    papktsizequerymodel.cpp \
    paprotooperation.cpp \
    paprotoquerymodel.cpp \
    pataskinfooperation.cpp \
    pataskinfoquerymodel.cpp \
    patcpsessionoperation.cpp \
    patcpsessionquerymodel.cpp \
    paudpsessionoperation.cpp \
    paudpsessionquerymodel.cpp \
    qocilogoperation.cpp \
    qocilogviewoperation.cpp \
    qociresultoperation.cpp \
    qociresultviewoperation.cpp \
    qocistatustypeoperation.cpp \
    qocitaskoperation.cpp \
    qocitaskviewoperation.cpp \
    qociuseroperation.cpp \
    paofflinefilequerymodel.cpp \
    paonlinepcapquerymodel.cpp \
    qocisoftwarestatus.cpp \
    qociuserstatusoperation.cpp \
    parecoveryfileoperation.cpp \
    qocitaskstatusoperation.cpp

HEADERS += qprivatesqlhelper.h\
        qprivatesqlhelper_global.h \
    paaddressoperation.h \
    paaddressquerymodel.h \
    paflowoperation.h \
    paflowquerymodel.h \
    paipv4sessionoperataion.h \
    paipv4sessionquerymodel.h \
    paipv6sessionoperation.h \
    paipv6sessionquerymodel.h \
    paofflinefileoperation.h \
    paofflinepcapoperation.h \
    paonlinefileoperation.h \
    paonlinepcapoperation.h \
    paphysicalsessionoperation.h \
    paphysicalsessionquerymodel.h \
    papktinfooperation.h \
    papktsizeoperation.h \
    papktsizequerymodel.h \
    paprotooperation.h \
    paprotoquerymodel.h \
    pataskinfooperation.h \
    pataskinfoquerymodel.h \
    patcpsessionoperation.h \
    patcpsessionquerymodel.h \
    paudpsessionoperation.h \
    paudpsessionquerymodel.h \
    qocilogoperation.h \
    qocilogviewoperation.h \
    qociresultoperation.h \
    qociresultviewoperation.h \
    qocistatustypeoperation.h \
    qocitaskoperation.h \
    qocitaskviewoperation.h \
    qociuseroperation.h \
    paofflinefilequerymodel.h \
    paonlinepcapquerymodel.h \
    qocisoftwarestatus.h \
    qociuserstatusoperation.h \
    parecoveryfileoperation.h \
    qocitaskstatusoperation.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPublicSqlHelper/release/ -lQPublicSqlHelper
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPublicSqlHelper/debug/ -lQPublicSqlHelper
else:unix: LIBS += -L$$OUT_PWD/../QPublicSqlHelper/ -lQPublicSqlHelper

INCLUDEPATH += $$PWD/../QPublicSqlHelper
DEPENDPATH += $$PWD/../QPublicSqlHelper

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPErrorHandle/release/ -lQPErrorHandle
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPErrorHandle/debug/ -lQPErrorHandle
else:unix: LIBS += -L$$OUT_PWD/../QPErrorHandle/ -lQPErrorHandle

INCLUDEPATH += $$PWD/../QPErrorHandle
DEPENDPATH += $$PWD/../QPErrorHandle

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPRecordModel/release/ -lQPRecordModel
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPRecordModel/debug/ -lQPRecordModel
else:unix: LIBS += -L$$OUT_PWD/../QPRecordModel/ -lQPRecordModel

INCLUDEPATH += $$PWD/../QPRecordModel
DEPENDPATH += $$PWD/../QPRecordModel
