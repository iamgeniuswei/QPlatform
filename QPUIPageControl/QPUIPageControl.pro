#-------------------------------------------------
#
# Project created by QtCreator 2015-05-11T10:17:08
#
#-------------------------------------------------

QT       += widgets sql

QT       -= gui

TARGET = QPUIPageControl
TEMPLATE = lib

DEFINES += QPUIPageControl_LIBRARY

SOURCES += \
    no_focus_delegate.cpp \
    datetimedelegate.cpp \
    datetimedelegatewithusecs.cpp \
    qpuipagecontrol.cpp \
    qpuipagecontroltoolbar.cpp

HEADERS +=\
        pagewidget_global.h \
    no_focus_delegate.h \
    pagewidget_p.h \
    private/dataoperationwidget_p.h \
    datetimedelegate.h \
    datetimedelegatewithusecs.h \
    qpuipagecontrol.h \
    qpuipagecontroltoolbar.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPUIControl/release/ -lQPUIControl
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPUIControl/debug/ -lQPUIControl
else:unix: LIBS += -L$$OUT_PWD/../QPUIControl/ -lQPUIControl

INCLUDEPATH += $$PWD/../QPUIControl
DEPENDPATH += $$PWD/../QPUIControl

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPublicSqlHelper/release/ -lQPublicSqlHelper
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPublicSqlHelper/debug/ -lQPublicSqlHelper
else:unix: LIBS += -L$$OUT_PWD/../QPublicSqlHelper/ -lQPublicSqlHelper

INCLUDEPATH += $$PWD/../QPublicSqlHelper
DEPENDPATH += $$PWD/../QPublicSqlHelper
