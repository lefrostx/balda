#include <QFile>
#include <QTextStream>
#include "fileloader.h"

GameBalda::FileLoader::FileLoader(const QString &filename)
{
    QFile file{filename};
    if (!file.exists())
        throw FileNotExistsException{};
}
