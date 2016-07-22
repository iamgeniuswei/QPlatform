#-------------------------------------------------
#
# Project created by QtCreator 2016-05-19T16:10:19
#
#-------------------------------------------------

QT       += widgets

TARGET = QPNetworkAssets
TEMPLATE = lib

DEFINES += QPNETWORKASSETS_LIBRARY

SOURCES += qpnetworkassets.cpp \
    qpassetviewbuilder.cpp \
    qpassetdetailbuilder.cpp

HEADERS += qpnetworkassets.h\
        qpnetworkassets_global.h \
    qpassetviewbuilder.h \
    qpassetdetailbuilder.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPUIControl/release/ -lQPUIControl
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPUIControl/debug/ -lQPUIControl
else:unix: LIBS += -L$$OUT_PWD/../QPUIControl/ -lQPUIControl

INCLUDEPATH += $$PWD/../QPUIControl
DEPENDPATH += $$PWD/../QPUIControl

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPUIPageControl/release/ -lQPUIPageControl
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPUIPageControl/debug/ -lQPUIPageControl
else:unix: LIBS += -L$$OUT_PWD/../QPUIPageControl/ -lQPUIPageControl

INCLUDEPATH += $$PWD/../QPUIPageControl
DEPENDPATH += $$PWD/../QPUIPageControl
