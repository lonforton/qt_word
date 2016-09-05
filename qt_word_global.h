#ifndef QT_WORD_GLOBAL_H
#define QT_WORD_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(QT_WORD_LIBRARY)
#  define QT_WORDSHARED_EXPORT Q_DECL_EXPORT
#else
#  define QT_WORDSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // QT_WORD_GLOBAL_H
