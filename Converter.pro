#-------------------------------------------------
#
# Project created by QtCreator 2017-02-09T08:59:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Converter
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
          parser.cpp

HEADERS  += mainwindow.h \
    parser.h

FORMS    += mainwindow.ui
