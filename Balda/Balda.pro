#-------------------------------------------------
#
# Project created by QtCreator 2016-08-02T22:53:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Balda
TEMPLATE = app

CONFIG += c++14

SOURCES += main.cpp\
        mainwindow.cpp \
    fileloader.cpp \
    gamelogic.cpp

HEADERS  += mainwindow.h \
    fileloader.h \
    gamelogic.h

FORMS    += mainwindow.ui
