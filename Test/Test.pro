#-------------------------------------------------
#
# Project created by QtCreator 2016-09-22T10:35:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Test
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    background.cpp \
    cdrawlayer.cpp \
    mapdata.cpp

HEADERS  += mainwindow.h \
    background.h \
    common.h \
    cdrawlayer.h \
    mapdata.h

FORMS    += mainwindow.ui
