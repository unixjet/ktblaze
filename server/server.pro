QT += core
QT -= gui

TARGET = server
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

#thirdparty configure
BOOST_DIR=E:\mgzhou\study\boost\boost_1_58_0
BOOST_LIBSPATH=$$BOOST_DIR\stage\qt-mingw32\lib


QMAKE_CXXFLAGS +=-march=i686
INCLUDEPATH += $$BOOST_DIR

LIBS +=-L$$BOOST_LIBSPATH
LIBS +=-lboost_system-mgw49-mt-1_58
LIBS +=-lboost_thread-mgw49-mt-1_58
LIBS +=-lws2_32
