#-------------------------------------------------
#
# Project created by QtCreator 2016-04-22T11:24:18
#
#-------------------------------------------------

QT       += core gui svg

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

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPUIControl/release/ -lQPUIControl
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPUIControl/debug/ -lQPUIControl
else:unix: LIBS += -L$$OUT_PWD/../QPUIControl/ -lQPUIControl

INCLUDEPATH += $$PWD/../QPUIControl
DEPENDPATH += $$PWD/../QPUIControl

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPMainFrame/release/ -lQPMainFrame
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPMainFrame/debug/ -lQPMainFrame
else:unix: LIBS += -L$$OUT_PWD/../QPMainFrame/ -lQPMainFrame

INCLUDEPATH += $$PWD/../QPMainFrame
DEPENDPATH += $$PWD/../QPMainFrame

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPMessageBox/release/ -lQPMessageBox
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPMessageBox/debug/ -lQPMessageBox
else:unix: LIBS += -L$$OUT_PWD/../QPMessageBox/ -lQPMessageBox

INCLUDEPATH += $$PWD/../QPMessageBox
DEPENDPATH += $$PWD/../QPMessageBox

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPCharts/release/ -lQPCharts
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPCharts/debug/ -lQPCharts
else:unix: LIBS += -L$$OUT_PWD/../QPCharts/ -lQPCharts

INCLUDEPATH += $$PWD/../QPCharts
DEPENDPATH += $$PWD/../QPCharts

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPTopology/release/ -lQPTopology
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPTopology/debug/ -lQPTopology
else:unix: LIBS += -L$$OUT_PWD/../QPTopology/ -lQPTopology

INCLUDEPATH += $$PWD/../QPTopology
DEPENDPATH += $$PWD/../QPTopology

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPNetworkAssets/release/ -lQPNetworkAssets
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPNetworkAssets/debug/ -lQPNetworkAssets
else:unix: LIBS += -L$$OUT_PWD/../QPNetworkAssets/ -lQPNetworkAssets

INCLUDEPATH += $$PWD/../QPNetworkAssets
DEPENDPATH += $$PWD/../QPNetworkAssets

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPUIPageControl/release/ -lQPUIPageControl
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPUIPageControl/debug/ -lQPUIPageControl
else:unix: LIBS += -L$$OUT_PWD/../QPUIPageControl/ -lQPUIPageControl

INCLUDEPATH += $$PWD/../QPUIPageControl
DEPENDPATH += $$PWD/../QPUIPageControl

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

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPRecordModel/release/ -lQPRecordModel
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPRecordModel/debug/ -lQPRecordModel
else:unix: LIBS += -L$$OUT_PWD/../QPRecordModel/ -lQPRecordModel

INCLUDEPATH += $$PWD/../QPRecordModel
DEPENDPATH += $$PWD/../QPRecordModel

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPrivateSqlHelper/release/ -lQPrivateSqlHelper
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPrivateSqlHelper/debug/ -lQPrivateSqlHelper
else:unix: LIBS += -L$$OUT_PWD/../QPrivateSqlHelper/ -lQPrivateSqlHelper

INCLUDEPATH += $$PWD/../QPrivateSqlHelper
DEPENDPATH += $$PWD/../QPrivateSqlHelper

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPNetworkTopology/release/ -lQPNetworkTopology
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPNetworkTopology/debug/ -lQPNetworkTopology
else:unix: LIBS += -L$$OUT_PWD/../QPNetworkTopology/ -lQPNetworkTopology

INCLUDEPATH += $$PWD/../QPNetworkTopology
DEPENDPATH += $$PWD/../QPNetworkTopology

FORMS += \
    form.ui

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPXMLHelper/release/ -lQPXMLHelper
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPXMLHelper/debug/ -lQPXMLHelper
else:unix: LIBS += -L$$OUT_PWD/../QPXMLHelper/ -lQPXMLHelper

INCLUDEPATH += $$PWD/../QPXMLHelper
DEPENDPATH += $$PWD/../QPXMLHelper

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPSIPTest/release/ -lQPSIPTest
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPSIPTest/debug/ -lQPSIPTest
else:unix: LIBS += -L$$OUT_PWD/../QPSIPTest/ -lQPSIPTest

INCLUDEPATH += $$PWD/../QPSIPTest
DEPENDPATH += $$PWD/../QPSIPTest
