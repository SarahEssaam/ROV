#-------------------------------------------------
#
# Project created by QtCreator 2016-10-27T19:05:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ROV1
TEMPLATE = app


SOURCES += main.cpp \
    joystick.cpp \
    mode1.cpp \
    mode2.cpp \
    mode3.cpp \
    mysfml.cpp \
    mysdl.cpp

HEADERS  += \
    joystick.h \
    mode1.h \
    mode2.h \
    mode3.h \
    mysfml.h \
    mysdl.h
