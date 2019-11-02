include(../mere-auth-lib/mere-auth-lib.pri)

QT += core

TARGET = mere-auth
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS MERE_AUTH

SOURCES += \
        src/main.cpp

INCLUDEPATH += /usr/local/include

#
# Install
#
unix
{
    target.path = /usr/local/bin
    INSTALLS += target
}
