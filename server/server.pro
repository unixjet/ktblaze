QT += core
QT += gui
QT += uitools

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = server
CONFIG += console
#CONFIG -= app_bundle


TEMPLATE = app

SOURCES += main.cpp \
    talk_to_client.cpp \
    ../common/utility.cpp \
    mainwindow.cpp \
    ../common/Object.cpp \
    ../common/Context.cpp \
    ../common/StringHash.cpp \
    ../common/RefCounted.cpp

#thirdparty configure
INCLUDEPATH +=$$PWD/../include
COMMON_DIR=$$PWD/../common

#xlsreader
INCLUDEPATH +=$$COMMON_DIR
SOURCES +=$$COMMON_DIR/XlsReader.cpp
DEFINES +=XLS_WIDE_STRINGS=0
LIBS +=-L$$PWD/../lib/
LIBS +=-lxlsreader -liconv

#boost
CONFIG +=c++11

#BOOST_DIR=E:\study\boost\boost_1_58_0
BOOST_DIR=E:\mgzhou\study\boost\boost_1_58_0
BOOST_LIBSPATH=$$BOOST_DIR\stage\qt-mingw32\lib

#QMAKE_CXXFLAGS +=-Wno-used-variable -Wno-used-parameter
QMAKE_CXXFLAGS +=-march=i686
QMAKE_CXXFLAGS -=-fpermissive
QMAKE_CXXFLAGS_CXX11 =-std=c++11
INCLUDEPATH += $$BOOST_DIR

LIBS +=-L$$BOOST_LIBSPATH
LIBS +=-lboost_system-mgw49-mt-1_58
LIBS +=-lboost_thread-mgw49-mt-1_58
LIBS +=-lboost_log_setup-mgw49-mt-1_58
LIBS +=-lboost_log-mgw49-mt-1_58
LIBS +=-lboost_date_time-mgw49-mt-1_58
LIBS +=-lboost_filesystem-mgw49-mt-1_58

#DEFINES +=_WIN32_WINDOWS
LIBS +=-lws2_32 -lmswsock

HEADERS += \
    talk_to_client.h \
    logger.hpp \
    ../common/utility.h \
    mainwindow.h \
    ../common/Object.h \
    ../common/StringHash.h \
    ../common/Context.h \
    ../common/RefCounted.h

FORMS    += \
         mainwindow.ui \
         ../res/interface/server.ui

