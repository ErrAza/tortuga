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
    dbconnect.cpp \
    user.cpp \
    loginmanager.cpp \
    project.cpp \
    scene.cpp \
    mainmenu.cpp \
    newprojectdialog.cpp \
    scenebox.cpp


HEADERS  += mainwindow.h \
    dbconnect.h \
    user.h \
    loginmanager.h \
    project.h \
    scene.h \
    mainmenu.h \
    newprojectdialog.h \
    scenebox.h


FORMS    += mainwindow.ui \
    mainmenu.ui \
    newprojectdialog.ui
