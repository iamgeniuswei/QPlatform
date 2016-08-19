#-------------------------------------------------
#
# Project created by QtCreator 2016-04-25T09:53:48
#
#-------------------------------------------------

QT       += widgets

TARGET = QPUIControl
TEMPLATE = lib

DEFINES += QPUICONTROL_LIBRARY

SOURCES += qpuicontrol.cpp \
    qpuiwidget.cpp \
    qpuinavigationbar.cpp \
    qpuistatusbar.cpp \
    qpuiwindow.cpp \
    qpuiwindowbuilder.cpp \
    qpuiwindowdirector.cpp \
    qpuiiconbutton.cpp \
    qpuipopupwindow.cpp \
    qpuipopupwindowbuilder.cpp \
    qpuipopupwindowdirector.cpp \
    qpuilineedit.cpp \
    qpuiview.cpp \
    qpuiviewbuilder.cpp \
    qpuistaticallabelbuilder.cpp \
    qpuistaticallabel.cpp \
    qpuiassetsummarylabel.cpp \
    qpuititlebar.cpp \
    qpuititlebarbuilder.cpp \
    qpuititlebardirector.cpp

HEADERS += qpuicontrol.h\
        qpuicontrol_global.h \
    qpuiwidget.h \
    private/qpuiwidget_p.h \
    qpuinavigationbar.h \
    qpuistatusbar.h \
    qpuiwindow.h \
    qpuiwindowbuilder.h \
    qpuiwindowdirector.h \
    private/qpuiwindow_p.h \
    qpuiiconbutton.h \
    private/qpuiiconbutton_p.h \
    qpuipopupwindow.h \
    private/qpuipopupwindow_p.h \
    qpuipopupwindowbuilder.h \
    qpuipopupwindowdirector.h \
    private/qpuistatusbar_p.h \
    qpuilineedit.h \
    private/qpuilineedit_p.h \
    qpuiview.h \
    private/qpuiview_p.h \
    qpuiviewbuilder.h \
    qpuistaticallabelbuilder.h \
    qpuistaticallabel.h \
    private/qpuistaticallabel_p.h \
    qpuiassetsummarylabel.h \
    private/qpuiassetsummarylabel_p.h \
    private/qpuititlebar_p.h \
    qpuititlebar.h \
    qpuititlebarbuilder.h \
    qpuititlebardirector.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
