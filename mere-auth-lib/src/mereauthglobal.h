#ifndef MEREAUTHGLOBAL_H
#define MEREAUTHGLOBAL_H

#include <QtCore/QtGlobal>

#if defined MERE_AUTH
 #define MERE_AUTH_LIBSPEC Q_DECL_EXPORT
#else
 #define MERE_AUTH_LIBSPEC Q_DECL_IMPORT
#endif

#endif // MEREAUTHGLOBAL_H
