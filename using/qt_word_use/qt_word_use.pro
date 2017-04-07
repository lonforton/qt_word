#-------------------------------------------------
#
# Project created by QtCreator 2016-10-16T23:07:33
#
#-------------------------------------------------

QT       += core axcontainer gui

TARGET = qt_word_use
CONFIG   += console

TEMPLATE = app

SOURCES += main.cpp \
    word_use.cpp

HEADERS += \
    word_use.h

CONFIG += c++11


win32: LIBS += -L$$PWD/../../bin/ -lqt_word

INCLUDEPATH += $$PWD/../../bin
DEPENDPATH += $$PWD/../../bin

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../../bin/qt_word.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/../../bin/libqt_word.a
