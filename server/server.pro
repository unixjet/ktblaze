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
    mainwindow.cpp \
    ../common/utility.cpp \
    ../common/Core/Context.cpp \
    ../common/Core/Object.cpp \
    ../common/Core/Variant.cpp \
    ../common/Core/Thread.cpp \
    ../common/Core/StringUtils.cpp \
    ../common/Container/Allocator.cpp \
    ../common/Container/HashBase.cpp \
    ../common/Container/RefCounted.cpp \
    ../common/Container/Str.cpp \
    ../common/Container/Swap.cpp \
    ../common/Container/VectorBase.cpp \
    ../common/Math/Vector4.cpp \
    ../common/Math/Vector3.cpp \
    ../common/Math/Vector2.cpp \
    ../common/Math/StringHash.cpp \
    ../common/Math/Sphere.cpp \
    ../common/Math/Rect.cpp \
    ../common/Math/Ray.cpp \
    ../common/Math/Random.cpp \
    ../common/Math/Quaternion.cpp \
    ../common/Math/Polyhedron.cpp \
    ../common/Math/Plane.cpp \
    ../common/Math/Matrix4.cpp \
    ../common/Math/Matrix3x4.cpp \
    ../common/Math/Matrix3.cpp \
    ../common/Math/Frustum.cpp \
    ../common/Math/Color.cpp \
    ../common/Math/BoundingBox.cpp \
    ../common/Math/AreaAllocator.cpp \
../common/IO/VectorBuffer.cpp \
../common/IO/Serializer.cpp \
../common/IO/Deserializer.cpp \



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

BOOST_DIR=E:\study\boost\boost_1_58_0
#BOOST_DIR=E:\mgzhou\study\boost\boost_1_58_0
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
    mainwindow.h

FORMS    += \
         mainwindow.ui \
         ../res/interface/server.ui

