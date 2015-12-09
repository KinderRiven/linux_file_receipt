#-------------------------------------------------
#
# Project created by QtCreator 2015-12-05T19:01:03
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SendServer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    sendfilewindow.cpp \
    recvserver.cpp \
    sendclient.cpp \
    crecvserver.cpp \
    csendclient.cpp \
    messagebox.cpp \
    settingwindow.cpp

HEADERS  += mainwindow.h \
    sendfilewindow.h \
    headfile.h \
    recvserver.h \
    sendclient.h \
    crecvserver.h \
    csendclient.h \
    messagebox.h \
    settingwindow.h

FORMS    += mainwindow.ui \
    sendfilewindow.ui \
    messagebox.ui \
    settingwindow.ui
