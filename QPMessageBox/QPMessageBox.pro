#-------------------------------------------------
#
# Project created by QtCreator 2016-04-28T10:02:18
#
#-------------------------------------------------

QT       += widgets

TARGET = QPMessageBox
TEMPLATE = lib

DEFINES += QPMESSAGEBOX_LIBRARY

SOURCES += \
    qpmessageboxtitlebuilder.cpp \
    qpmessageboxarea.cpp \
    qpmessageboxbuilder.cpp \
    qpmessagebox.cpp

HEADERS +=\
        qpmessagebox_global.h \
    qpmessageboxtitlebuilder.h \
    private/qpmessageboxtitlebuilder_p.h \
    private/qpmessageboxarea_p.h \
    qpmessageboxarea.h \
    qpmessageboxbuilder.h \
    qpmessagebox.h \
    private/qpmessagebox_p.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPUIControl/release/ -lQPUIControl
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPUIControl/debug/ -lQPUIControl
else:unix: LIBS += -L$$OUT_PWD/../QPUIControl/ -lQPUIControl

INCLUDEPATH += $$PWD/../QPUIControl
DEPENDPATH += $$PWD/../QPUIControl
