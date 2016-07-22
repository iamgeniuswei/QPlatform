#-------------------------------------------------
#
# Project created by QtCreator 2015-06-15T17:30:24
#
#-------------------------------------------------

QT       -= gui sql

TARGET = QPRecordModel
TEMPLATE = lib

DEFINES += DBMODEL_LIBRARY

SOURCES += dbmodel.cpp \
    syslog.cpp \
    syslogview.cpp \
    sysresult.cpp \
    systask.cpp \
    systaskstatus.cpp \
    sysstatusview.cpp \
    sysuser.cpp \
    syslogtype.cpp \
    paofflinemodel.cpp \
    paonlinemodel.cpp \
    sysresultview.cpp \
    sysviewuser.cpp \
    softwarestatus.cpp \
    userstatus.cpp \
    taskstatus.cpp

HEADERS += dbmodel.h\
        dbmodel_global.h \
    syslogview.h \
    syslog.h \
    sysresult.h \
    systask.h \
    systaskstatus.h \
    sysstatusview.h \
    sysuser.h \
    syslogtype.h \
    paofflinemodel.h \
    paonlinemodel.h \
    sysresultview.h \
    sysviewuser.h \
    softwarestatus.h \
    userstatus.h \
    taskstatus.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
