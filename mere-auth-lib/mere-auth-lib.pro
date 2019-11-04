include(../../mere-utils/mere-utils-lib/mere-utils-lib.pri)

QT = core

CONFIG += c++11
CONFIG += shared

TARGET   = mere-auth
VERSION  = 0.0.1b
TEMPLATE = lib

DEFINES += LIB_CODE=\\\"$$TARGET\\\"
DEFINES += LIB_NAME=\\\"$$TARGET\\\"
DEFINES += LIB_VERSION=\\\"$$VERSION\\\"
DEFINES += QT_DEPRECATED_WARNINGS MERE_AUTH_LIB

SOURCES += \
    src/mereauth.cpp \
    src/mereaccount.cpp \
    src/mereapplicant.cpp \
    src/pam/merepam.cpp

HEADERS += \
    src/mereauth.h \
    src/mereaccount.h \
    src/mereauthglobal.h \
    src/mereapplicant.h \
    src/pam/merepam.h

DESTDIR = $$PWD/../lib

LIBS += -lpam

#
# Install
#
unix {
    target.path = /usr/local/lib
    INSTALLS += target

    INSTALL_PREFIX = /usr/local/include/mere/auth
    for(header, HEADERS) {
        sdir = $${dirname(header)}
        sdir = $$replace(sdir, "src", "")
        path = $${INSTALL_PREFIX}$${sdir}

        eval(headers_$${path}.files += $$header)
        eval(headers_$${path}.path = $$path)
        eval(INSTALLS *= headers_$${path})
    }
}
