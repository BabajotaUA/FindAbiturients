#-------------------------------------------------
#
# Project created by QtCreator 2013-07-10T18:42:47
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FindAbiturients
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    controller.cpp \
    datasource.cpp \
    dataresult.cpp

HEADERS  += mainwindow.h \
    controller.h \
    datasource.h \
    dataresult.h

FORMS    += mainwindow.ui
