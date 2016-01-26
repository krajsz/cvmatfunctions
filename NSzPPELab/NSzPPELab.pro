TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG +=C++11

SOURCES += main.cpp \
    myprocessingclass.cpp \
    cvmatfunctions.cpp \
    opticdisc.cpp \
    coordinate.cpp \
    mypair.cpp \
    size.cpp \
    utils.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    myprocessingclass.h \
    cvmatfunctions.h \
    opticdisc.h \
    coordinate.h \
    mypair.h \
    size.h \
    utils.h
CONFIG += C++11
INCLUDEPATH +=-I/usr/local/include \
                -I/usr/local/include/opencv

QMAKE_CXXFLAGS+= -fopenmp
QMAKE_LFLAGS  += -fopenmp

LIBS += `pkg-config opencv --libs --cflags`
