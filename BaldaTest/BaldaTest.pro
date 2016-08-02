#-------------------------------------------------
#
# Project created by QtCreator 2016-08-02T23:29:38
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_baldatestfileloadertest
CONFIG   += console
CONFIG   += c++14
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_baldatestfileloadertest.cpp \
    ../Balda/fileloader.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    ../Balda/fileloader.h
