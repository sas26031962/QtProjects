#-------------------------------------------------
#
# Project created by QtCreator 2014-05-15T09:40:35
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtSQL0
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    classes/cdatabase.cpp \
    classes/cindexdataset.cpp \
    classes/ctreeitem.cpp

HEADERS  += mainwindow.h \
    classes/Constants.h \
    classes/cdatabase.h \
    classes/cindexdataset.h \
    classes/ctreeitem.h

FORMS    += mainwindow.ui
