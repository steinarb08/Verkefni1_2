#-------------------------------------------------
#
# Project created by QtCreator 2015-12-10T12:44:44
#
#-------------------------------------------------
QT      += sql
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = verkefni3
TEMPLATE = app


SOURCES += main.cpp\
        mainscreen.cpp \
    computer.cpp \
    cplink.cpp \
    datalayer.cpp \
    domainlayer.cpp \
    person.cpp

HEADERS  += mainscreen.h \
    computer.h \
    cplink.h \
    datalayer.h \
    domainlayer.h \
    person.h

FORMS    += mainscreen.ui
