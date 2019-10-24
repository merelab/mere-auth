QT       += core

TARGET = mere-auth
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS MERE_AUTH

SOURCES += \
        src/main.cpp

INCLUDEPATH += src
INCLUDEPATH += ../include
INCLUDEPATH += /usr/local/include

DEPENDPATH  += . ../lib

LIBS += -L$$PWD/../lib -lmere-auth

#
# Install
#
unix
{
    target.path = /usr/local/bin
    INSTALLS += target
}
