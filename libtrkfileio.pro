#TEMPLATE = lib
#CONFIG += staticlib
CONFIG += console
#CONFIG -= app_bundle
CONFIG += c++11

SOURCES += main.cpp \
    FiberData.cpp

HEADERS += \
    FiberData.h \
    defs.h

CONFIG(debug, debug|release){
    TARGET = TrkFileIOd
}
CONFIG(release, debug|release){
    TARGET = TrkFileIO
}

DESTDIR = $${OUT_PWD}
