#-------------------------------------------------
#
# Project created by QtCreator 2016-05-16T09:04:04
#
#-------------------------------------------------

QT       += widgets printsupport

TARGET = QPCharts
TEMPLATE = lib

DEFINES += QPCHARTS_LIBRARY

SOURCES += qpcharts.cpp \
    qcustomplot.cpp \
    qprealtimechart.cpp \
    qpstaffgauge.cpp

HEADERS += qpcharts.h\
        qpcharts_global.h \
    qcustomplot.h \
    qprealtimechart.h \
    private/qprealtimechart_p.h \
    private/qpcharts_p.h \
    qpstaffgauge.h \
    private/qpstaffgauge_p.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
