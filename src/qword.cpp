#include "qword.h"

#include <QDebug>

QWord::QWord()
{
    ::CoInitializeEx(NULL, COINIT_MULTITHREADED);

    // add functions

    _func_map.insert(funcs::add_simple,   "Add()");
    _func_map.insert(funcs::close_simple, "Close()");
    _func_map.insert(funcs::quit_simple,  "Quit()");
    _func_map.insert(funcs::open_simple,  "Open(const QVariant&)");
    _func_map.insert(funcs::open_full,    "Open(const QVariant&, const QVariant&, const QVariant&, const QVariant&,"
                                               "const QVariant&, const QVariant&, const QVariant&)");

    // add objects

    _objs_map.insert(objs::word_app,      "Word.Application");
    _objs_map.insert(objs::docs,          "Documents()");

    // add properties

    _props_map.insert(props::visible,     "Visible");
}

QWord::~QWord()
{
    _word_app->clear();
}

void QWord::startWord()
{
    _word_app = new QAxObject(_objs_map[objs::word_app]);

    QAxObject *word_app_docs = _word_app->querySubObject(_objs_map[objs::docs]);
    word_app_docs->querySubObject(_func_map[funcs::add_simple]);

    _word_app->setProperty(_props_map[props::visible], true);
}

void QWord::openDocument(const QString path)
{
    _word_app = new QAxObject(_objs_map[objs::word_app]);
    QAxObject *word_app_docs = _word_app->querySubObject(_objs_map[objs::docs]);
    if(!word_app_docs){
        _word_app->dynamicCall(_func_map[funcs::quit_simple]);
        return ;
    }

    QVariant filename(path);

    if(!word_app_docs->querySubObject(_func_map[funcs::open_simple], filename)){
        word_app_docs->dynamicCall(_func_map[funcs::close_simple]);
        _word_app->dynamicCall(_func_map[funcs::quit_simple]);
        return ;
    }

    _word_app->setProperty(_props_map[props::visible], true);
}


// @param QString path
// @param bool read_only
// @param bool confirm_conversions
// @param bool add_to_recent_files
// @param QString password_document
// @param QString password_template
// @param bool revert
// @return void
void QWord::openDocument(const QString path, QVariant read_only, QVariant confirm_conversions, QVariant add_to_recent_files,
                  QVariant password_document, QVariant password_template, QVariant revert)
{
    QVariant filename(path);

    /*
     * check if parameters have a right type, otherwise set default values
     * using static_cast to treat QVariant::Type as QMetaType::Type (safe here)
     */

    if(static_cast<QMetaType::Type>(read_only.type()) != QMetaType::Bool){
        read_only = QVariant(false);
    }
    if(static_cast<QMetaType::Type>(confirm_conversions.type()) != QMetaType::Bool){
        confirm_conversions = QVariant(false);
    }
    if(static_cast<QMetaType::Type>(add_to_recent_files.type()) != QMetaType::Bool){
        add_to_recent_files = QVariant(false);
    }
    if(static_cast<QMetaType::Type>(password_document.type()) != QMetaType::QString){
        password_document = QVariant("");
    }
    if(static_cast<QMetaType::Type>(password_template.type()) != QMetaType::QString){
        password_template = QVariant("");
    }
    if(static_cast<QMetaType::Type>(revert.type()) != QMetaType::Bool){
        revert = QVariant(false);
    }

    _word_app = new QAxObject(_objs_map[objs::word_app]);
    QAxObject *word_app_docs = _word_app->querySubObject(_objs_map[objs::docs]);
    if(!word_app_docs){
        _word_app->dynamicCall(_func_map[funcs::quit_simple]);
        return ;
    }

    if(!word_app_docs->querySubObject(_func_map[funcs::open_full], filename, confirm_conversions, read_only,
                                      add_to_recent_files, password_document, password_template, revert))
    {
        word_app_docs->dynamicCall(_func_map[funcs::close_simple]);
        _word_app->dynamicCall(_func_map[funcs::quit_simple]);
        return ;
    }

    _word_app->setProperty(_props_map[props::visible], true);

}
