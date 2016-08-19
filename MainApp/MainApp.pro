#-------------------------------------------------
#
# Project created by QtCreator 2016-04-22T11:24:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MainApp
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    slidingwindow.cpp \
    form.cpp \
    testform.cpp \
    testscorllarea.cpp \
    testwidget.cpp \
    qpuitimelinelist.cpp

HEADERS  += widget.h \
    slidingwindow.h \
    form.h \
    testform.h \
    testscorllarea.h \
    testwidget.h \
    qpuitimelinelist.h

RESOURCES += \
    ../resource/software.qrc

FORMS += \
    form.ui \
    testform.ui \
    testscorllarea.ui

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPErrorHandle/release/ -lQPErrorHandle
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPErrorHandle/debug/ -lQPErrorHandle
else:unix: LIBS += -L$$OUT_PWD/../QPErrorHandle/ -lQPErrorHandle

INCLUDEPATH += $$PWD/../QPErrorHandle
DEPENDPATH += $$PWD/../QPErrorHandle

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPublicSqlHelper/release/ -lQPublicSqlHelper
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPublicSqlHelper/debug/ -lQPublicSqlHelper
else:unix: LIBS += -L$$OUT_PWD/../QPublicSqlHelper/ -lQPublicSqlHelper

INCLUDEPATH += $$PWD/../QPublicSqlHelper
DEPENDPATH += $$PWD/../QPublicSqlHelper

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPUIControl/release/ -lQPUIControl
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPUIControl/debug/ -lQPUIControl
else:unix: LIBS += -L$$OUT_PWD/../QPUIControl/ -lQPUIControl

INCLUDEPATH += $$PWD/../QPUIControl
DEPENDPATH += $$PWD/../QPUIControl
