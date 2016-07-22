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
    form.cpp

HEADERS  += widget.h \
    slidingwindow.h \
    form.h

RESOURCES += \
    ../resource/software.qrc

FORMS += \
    form.ui

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPErrorHandle/release/ -lQPErrorHandle
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPErrorHandle/debug/ -lQPErrorHandle
else:unix: LIBS += -L$$OUT_PWD/../QPErrorHandle/ -lQPErrorHandle

INCLUDEPATH += $$PWD/../QPErrorHandle
DEPENDPATH += $$PWD/../QPErrorHandle
