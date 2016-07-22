#-------------------------------------------------
#
# Project created by QtCreator 2016-04-27T15:01:51
#
#-------------------------------------------------

QT       += widgets

TARGET = QPMainFrame
TEMPLATE = lib

DEFINES += QPMAINFRAME_LIBRARY

SOURCES += qpmainframe.cpp \
    qpmainwindowbuilder.cpp \
    qpmaintitlebuilder.cpp

HEADERS += qpmainframe.h\
        qpmainframe_global.h \
    qpmainwindowbuilder.h \
    qpmaintitlebuilder.h \
    private/qpmaintitlebuilder_p.h \
    private/qpmainwindowbuilder_p.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPUIControl/release/ -lQPUIControl
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPUIControl/debug/ -lQPUIControl
else:unix: LIBS += -L$$OUT_PWD/../QPUIControl/ -lQPUIControl

INCLUDEPATH += $$PWD/../QPUIControl
DEPENDPATH += $$PWD/../QPUIControl

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPNetworkAssets/release/ -lQPNetworkAssets
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPNetworkAssets/debug/ -lQPNetworkAssets
else:unix: LIBS += -L$$OUT_PWD/../QPNetworkAssets/ -lQPNetworkAssets

INCLUDEPATH += $$PWD/../QPNetworkAssets
DEPENDPATH += $$PWD/../QPNetworkAssets

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPSIPTest/release/ -lQPSIPTest
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPSIPTest/debug/ -lQPSIPTest
else:unix: LIBS += -L$$OUT_PWD/../QPSIPTest/ -lQPSIPTest

INCLUDEPATH += $$PWD/../QPSIPTest
DEPENDPATH += $$PWD/../QPSIPTest
