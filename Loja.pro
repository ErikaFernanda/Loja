#-------------------------------------------------
#
# Project created by QtCreator 2022-10-18T18:16:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Loja
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    loja-main.cpp \
    loja.cpp \
    loja_incompleto.cpp

HEADERS  += mainwindow.h \
    loja.h \
    loja_incompleto.h

FORMS    += mainwindow.ui

DISTFILES += \
    Loja.cbp \
    loja.txt
