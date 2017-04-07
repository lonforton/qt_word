#include <QDebug>
#include <QFileDialog>

#include "word_use.h"
#include "../../src/qword.h"

WordUse::WordUse()
{

}

int WordUse::start()
{
    QWord *word = new QWord;

    //word->startWord();
    //word->openDocument(QFileDialog::getOpenFileName(0, QObject::tr("Choose file")));
    word->openDocument(QFileDialog::getOpenFileName(0, QObject::tr("Choose file")), false, false, false, "", "", false);

    return 0;
}
