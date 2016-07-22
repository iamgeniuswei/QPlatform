#-------------------------------------------------
#
# Project created by QtCreator 2016-04-27T14:59:21
#
#-------------------------------------------------

QT       += widgets

TARGET = QPMainWindow
TEMPLATE = lib

DEFINES += QPMAINWINDOW_LIBRARY

SOURCES += qpmainwindow.cpp

HEADERS += qpmainwindow.h\
        qpmainwindow_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
