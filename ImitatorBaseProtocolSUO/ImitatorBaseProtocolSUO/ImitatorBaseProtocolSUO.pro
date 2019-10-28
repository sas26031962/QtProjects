#-------------------------------------------------
#
# Project created by QtCreator 2016-06-23T09:14:11
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BaseProtocol
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    bpmessages.cpp

HEADERS  += widget.h \
    bpmessages.h

FORMS    += widget.ui
