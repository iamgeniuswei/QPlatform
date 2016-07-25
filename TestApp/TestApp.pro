QT += core sql
QT -= gui

CONFIG += c++11

TARGET = TestApp
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPublicSqlHelper/release/ -lQPublicSqlHelper
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPublicSqlHelper/debug/ -lQPublicSqlHelper
else:unix: LIBS += -L$$OUT_PWD/../QPublicSqlHelper/ -lQPublicSqlHelper

INCLUDEPATH += $$PWD/../QPublicSqlHelper
DEPENDPATH += $$PWD/../QPublicSqlHelper

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPErrorHandle/release/ -lQPErrorHandle
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPErrorHandle/debug/ -lQPErrorHandle
else:unix: LIBS += -L$$OUT_PWD/../QPErrorHandle/ -lQPErrorHandle

INCLUDEPATH += $$PWD/../QPErrorHandle
DEPENDPATH += $$PWD/../QPErrorHandle
