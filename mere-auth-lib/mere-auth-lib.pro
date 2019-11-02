QT       += core

CONFIG += c++11
CONFIG += shared

TARGET   = mere-auth
TEMPLATE = lib


DEFINES += QT_DEPRECATED_WARNINGS MERE_AUTH_LIB

SOURCES += \
    src/mereaccount.cpp \
    src/mereauth.cpp \
    src/pam/merepam.cpp \
    src/mereapplicant.cpp

HEADERS += \
    src/mereaccount.h \
    src/mereauthglobal.h \
    src/mereauth.h \
    src/pam/merepam.h \
    src/mereapplicant.h

INCLUDEPATH += src
INCLUDEPATH += ../include
INCLUDEPATH += ../../mere-utils/include
INCLUDEPATH += /usr/local/include

DEPENDPATH  +=. ../../mere-utils/lib
LIBS += -L../../mere-utils/lib  -lmere-utils
LIBS += -lpam

LIBDIR = $$PWD/../lib
INCDIR = $$PWD/../include
DESTDIR = \"$$LIBDIR\"

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
