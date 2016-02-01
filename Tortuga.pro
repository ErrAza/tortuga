#-------------------------------------------------
#
# Project created by QtCreator 2016-02-01T12:13:59
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tortuga
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dbconnect.cpp

HEADERS  += mainwindow.h \
    dbconnect.h

FORMS    += mainwindow.ui
