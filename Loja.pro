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
    MainLoja.cpp \
    incluircd.cpp \
    incluirdvd.cpp \
    incluirlivro.cpp\
#    notepad.cpp
#    loja-main.cpp \
     loja.cpp

HEADERS  += \
    MainLoja.h \
#    notepad.h\
    incluircd.h \
    incluirdvd.h \
    incluirlivro.h \
    loja.h

FORMS    += \
    MainLoja.ui \
#    notepad.ui\
 \#    MainLoja_main.ui
    incluircd.ui \
    incluirdvd.ui \
    incluirlivro.ui

DISTFILES += \
    Loja.cbp \
    loja.txt
