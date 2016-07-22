#-------------------------------------------------
#
# Project created by QtCreator 2015-12-10T09:14:05
#
#-------------------------------------------------

QT       += widgets svg

TARGET = QPTopology
TEMPLATE = lib

DEFINES += QPTOPOLOGY_LIBRARY

SOURCES += qptopology.cpp \
    qplinkelement.cpp \
    qpnodeattribute.cpp \
    qptopologyarea.cpp \
    qptopologynode.cpp \
    qpnode.cpp \
    qpcabinetnode.cpp \
    qprouternode.cpp \
    qpswitchnode.cpp

HEADERS += qptopology.h\
        qptopology_global.h \
    misc_enum.h \
    qplinkelement.h \
    private/qplinkelement_p.h \
    private/qpnodeattribute_p.h \
    qpnodeattribute.h \
    qptopologyarea.h \
    private/qptopologyarea_p.h \
    private/qptopologynode_p.h \
    qptopologynode.h \
    qpnode.h \
    qpcabinetnode.h \
    qprouternode.h \
    qpswitchnode.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPUIControl/release/ -lQPUIControl
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPUIControl/debug/ -lQPUIControl
else:unix: LIBS += -L$$OUT_PWD/../QPUIControl/ -lQPUIControl

INCLUDEPATH += $$PWD/../QPUIControl
DEPENDPATH += $$PWD/../QPUIControl
