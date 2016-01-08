QT += core
QT -= gui

TARGET = client
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

#thirdparty configure

CONFIG += c++11



BOOST_DIR=E:\mgzhou\study\boost\boost_1_58_0
BOOST_LIBSPATH=$$BOOST_DIR\stage\qt-mingw32\lib

#QMAKE_CXXFLAGS +=-Wno-used-variable -Wno-used-parameter
QMAKE_CXXFLAGS +=-march=i686
QMAKE_CXXFLAGS -=-fpermissive
INCLUDEPATH += $$BOOST_DIR

LIBS +=-L$$BOOST_LIBSPATH
LIBS +=-lboost_system-mgw49-mt-1_58
LIBS +=-lboost_thread-mgw49-mt-1_58

#DEFINES +=_WIN32_WINDOWS
LIBS +=-lws2_32 -lmswsock
