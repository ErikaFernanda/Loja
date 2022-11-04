#-------------------------------------------------
#
# Project created by QtCreator 2022-10-18T18:16:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Loja
TEMPLATE = app


SOURCES +=main.cpp\
    frame.cpp \
    notepad.cpp
#    loja-main.cpp \
#    loja.cpp

HEADERS  += \
    frame.h \
    notepad.h\
    loja.h

FORMS    += \
    frame.ui \
    notepad.ui\
#    frame_main.ui

DISTFILES += \
    Loja.cbp \
    loja.txt
