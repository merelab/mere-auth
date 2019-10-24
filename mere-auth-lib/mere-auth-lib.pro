QT       += core

TARGET = mere-auth
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

INCLUDEPATH += ../../mere-utils/include
DEPENDPATH  +=. ../../mere-utils/lib

LIBS += -L../../mere-utils/lib
LIBS += -lmere-utils -lpam

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
