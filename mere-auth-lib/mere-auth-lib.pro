#-------------------------------------------------
#
# Project created by QtCreator 2018-09-15T23:26:09
#
#-------------------------------------------------

QT       += core

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mere-auth
TEMPLATE = lib

DEFINES += QT_DEPRECATED_WARNINGS MERE_LOGIN

SOURCES += \
    src/mereauth.cpp \
    src/pam/merepam.cpp \
    src/mereapplicant.cpp

HEADERS += \
    src/mereauthglobal.h \
    src/mereauth.h \
    src/pam/merepam.h \
    src/mereapplicant.h

FORMS +=

DEPENDPATH  +=. ../../mere-utils/lib
INCLUDEPATH += ../../mere-utils/include
LIBS += -L../../mere-utils/lib  -lmere-utils -lpam

LIBDIR = $$PWD/../lib
INCDIR = $$PWD/../include
DESTDIR = \"$$LIBDIR\"

for(HEADER, $$HEADERS)
{
#    QMAKE_POST_LINK += $$QMAKE_COPY $$quote($$PWD/$$HEADER) $$quote($$INCDIR) $$escape_expand(\\n\\t)
}
QMAKE_POST_LINK += $$QMAKE_COPY $$quote($$PWD/$$HEADERS) $$quote($$INCDIR) $$escape_expand(\\n\\t)

#
# Install
#
unix{
  target.path = /usr/local/lib
  INSTALLS += target
}
