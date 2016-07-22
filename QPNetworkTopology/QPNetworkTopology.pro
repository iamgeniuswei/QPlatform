#-------------------------------------------------
#
# Project created by QtCreator 2016-05-24T11:27:19
#
#-------------------------------------------------

QT       += widgets svg

TARGET = QPNetworkTopology
TEMPLATE = lib

DEFINES += QPNETWORKTOPOLOGY_LIBRARY

SOURCES += qpnetworktopology.cpp \
    qprangeroomview.cpp \
    qprangeroomxmlparser.cpp \
    qprangeroomserialize.cpp

HEADERS += qpnetworktopology.h\
        qpnetworktopology_global.h \
    qprangeroomview.h \
    qprangeroomxmlparser.h \
    qprangeroomserialize.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPTopology/release/ -lQPTopology
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPTopology/debug/ -lQPTopology
else:unix: LIBS += -L$$OUT_PWD/../QPTopology/ -lQPTopology

INCLUDEPATH += $$PWD/../QPTopology
DEPENDPATH += $$PWD/../QPTopology

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPUIControl/release/ -lQPUIControl
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPUIControl/debug/ -lQPUIControl
else:unix: LIBS += -L$$OUT_PWD/../QPUIControl/ -lQPUIControl

INCLUDEPATH += $$PWD/../QPUIControl
DEPENDPATH += $$PWD/../QPUIControl

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPXMLHelper/release/ -lQPXMLHelper
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPXMLHelper/debug/ -lQPXMLHelper
else:unix: LIBS += -L$$OUT_PWD/../QPXMLHelper/ -lQPXMLHelper

INCLUDEPATH += $$PWD/../QPXMLHelper
DEPENDPATH += $$PWD/../QPXMLHelper
