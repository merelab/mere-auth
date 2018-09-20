#-------------------------------------------------
#
# Project created by QtCreator 2018-09-15T23:26:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mere-auth
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS MERE_AUTH

SOURCES += \
        src/main.cpp

HEADERS +=

FORMS +=

DEPENDPATH += . ../lib
INCLUDEPATH += ../include

LIBS += -L$$PWD/../lib -lmere-auth -lpam

#
# Install
#
unix{
    target.path = /usr/local/bin
    INSTALLS += target
}
