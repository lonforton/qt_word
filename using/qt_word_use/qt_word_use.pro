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


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../build/release/ -lqt_word
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../build/debug/ -lqt_word

INCLUDEPATH += $$PWD/../../build/debug
DEPENDPATH += $$PWD/../../build/debug

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../build/release/libqt_word.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../build/debug/libqt_word.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../build/release/qt_word.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../build/debug/qt_word.lib
