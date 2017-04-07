#-------------------------------------------------
#
# Project created by QtCreator 2016-09-05T17:07:29
# Qt Word Library
#
#-------------------------------------------------

QT       -= gui
QT       += axcontainer

TARGET = qt_word
TEMPLATE = lib

CONFIG += c++11

DEFINES += QT_WORD_LIBRARY

SOURCES += qword.cpp

HEADERS += qword.h\
        qt_word_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
