#-------------------------------------------------
#
# Project created by QtCreator 2016-08-03T01:10:15
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_baldalogictest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_baldalogictest.cpp \
    ../Balda/gamelogic.cpp \
    ../Balda/fileloader.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    ../Balda/matrix.h \
    ../Balda/gamelogic.h \
    ../Balda/fileloader.h
