#-------------------------------------------------
#
# Project created by QtCreator 2015-04-30T11:22:20
#
#-------------------------------------------------

QT       -= gui
QT       += sql

TARGET = QPErrorHandle
TEMPLATE = lib

DEFINES += ERRORHANDLE_LIBRARY


SOURCES += \
    errorhandle.cpp \
    qperrorinfo.cpp \
    qperrorinfoqueue.cpp

HEADERS += errorhandle.h\
        errorhandle_global.h \
    qperrorinfo.h \
    private/qperrorinfo_p.h \
    private/qperrorinfoqueue_p.h \
    qperrorinfoqueue.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

