#-------------------------------------------------
#
# Project created by QtCreator 2016-09-22T10:35:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Test
TEMPLATE = app

INCLUDEPATH += ../include
LIBS += ../lua51.lib


SOURCES += main.cpp\
        mainwindow.cpp \
    background.cpp \
    cdrawlayer.cpp \
    mapdata.cpp \
    luaengine.cpp

HEADERS  += mainwindow.h \
    background.h \
    common.h \
    cdrawlayer.h \
    mapdata.h \
    luaengine.h

FORMS    += mainwindow.ui
