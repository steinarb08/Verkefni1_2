QT += core
QT += sql
QT -= gui

TARGET = Verk1_2
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    datalayer.cpp \
    domainlayer.cpp \
    person.cpp \
    replayer.cpp \
    computer.cpp \
    cplink.cpp

HEADERS += \
    datalayer.h \
    domainlayer.h \
    person.h \
    replayer.h \
    computer.h \
    cplink.h

