#-------------------------------------------------
#
# Project created by QtCreator 2015-05-09T15:08:14
#
#-------------------------------------------------

QT       += core sql


TARGET = QPublicSqlHelper
TEMPLATE = lib

DEFINES += SQLHELPER_LIBRARY

SOURCES += sqlhelper.cpp \
    qpdataoperation.cpp \
    sqlobjectfactory.cpp \    
    qpocidataoperation.cpp \
    sqlerror.cpp \    
    qpsqlconnection.cpp \
    qpsqlcommand.cpp \
    qpocisqlcommand.cpp \
    qpsqlworkthread.cpp \
    qpquerythread.cpp \
    qpnonquerythread.cpp \
    qpquerymodel.cpp \
    qpdatamodel.cpp \
    qpsqlsqlcommand.cpp

HEADERS += sqlhelper.h\
        sqlhelper_global.h \
    qpdataoperation.h \
    sqlobjectfactory.h \
    qpocidataoperation.h \
    sqlerror.h \    
    private/qpdataoperation_p.h \
    qpsqlconnection.h \
    qpsqlcommand.h \
    qpocisqlcommand.h \
    qpsqlworkthread.h \
    qpquerythread.h \
    qpnonquerythread.h \
    qpquerymodel.h \
    qpdatamodel.h \
    private/qpsqlconnection_p.h \
    qpsqlsqlcommand.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}



win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPErrorHandle/release/ -lQPErrorHandle
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPErrorHandle/debug/ -lQPErrorHandle
else:unix: LIBS += -L$$OUT_PWD/../QPErrorHandle/ -lQPErrorHandle

INCLUDEPATH += $$PWD/../QPErrorHandle
DEPENDPATH += $$PWD/../QPErrorHandle

