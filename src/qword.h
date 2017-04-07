#ifndef QWORD_H
#define QWORD_H

#include <QAxObject>
#include <QAxBase>
#include <QAxWidget>

#include "objbase.h"

#include "qt_word_global.h"

class QT_WORDSHARED_EXPORT QWord
{

public:
    QWord();
    ~QWord();

    enum class funcs{add_simple, close_simple, open_simple, open_full, quit_simple};
    enum class objs{docs, proj, word_app};
    enum class props{visible};

    void startWord();
    void openDocument(const QString path);
    void openDocument(const QString path, QVariant read_only, QVariant confirm_conversions, QVariant add_to_recent_files,
                      QVariant password_document, QVariant password_template, QVariant revert);

private:
    QAxObject *_word_app;

    QMap<funcs, const char *> _func_map;
    QMap<objs, const char *> _objs_map;
    QMap<props, const char *> _props_map;

};

#endif // QWORD_H
