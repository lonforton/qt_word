#include <QApplication>

#include "word_use.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    WordUse word_use;
    word_use.start();

    return a.exec();
}
