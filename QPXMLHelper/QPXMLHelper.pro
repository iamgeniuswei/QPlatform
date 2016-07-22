#-------------------------------------------------
#
# Project created by QtCreator 2016-05-31T10:46:12
#
#-------------------------------------------------

QT       += xml

QT       -= gui

TARGET = QPXMLHelper
TEMPLATE = lib

DEFINES += QPXMLHELPER_LIBRARY

SOURCES += qpxmlhelper.cpp \
    tinyxml2.cpp \
    qpxmlserialize.cpp

HEADERS += qpxmlhelper.h\
        qpxmlhelper_global.h \
    tinyxml2.h \
    qpxmlserialize.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
