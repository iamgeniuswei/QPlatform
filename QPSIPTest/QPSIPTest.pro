#-------------------------------------------------
#
# Project created by QtCreator 2016-06-14T15:05:31
#
#-------------------------------------------------

QT       += widgets svg

TARGET = QPSIPTest
TEMPLATE = lib

DEFINES += QPSIPTEST_LIBRARY

SOURCES += qpsiptest.cpp \
    qpsiptopologyview.cpp \
    sipfuzzyview.cpp

HEADERS += qpsiptest.h\
        qpsiptest_global.h \
    qpsiptopologyview.h \
    sipfuzzyview.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPUIControl/release/ -lQPUIControl
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPUIControl/debug/ -lQPUIControl
else:unix: LIBS += -L$$OUT_PWD/../QPUIControl/ -lQPUIControl

INCLUDEPATH += $$PWD/../QPUIControl
DEPENDPATH += $$PWD/../QPUIControl

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPTopology/release/ -lQPTopology
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPTopology/debug/ -lQPTopology
else:unix: LIBS += -L$$OUT_PWD/../QPTopology/ -lQPTopology

INCLUDEPATH += $$PWD/../QPTopology
DEPENDPATH += $$PWD/../QPTopology

FORMS += \
    sipfuzzyview.ui
