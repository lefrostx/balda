#include <QFile>
#include <QTextStream>
#include "fileloader.h"

GameBalda::FileLoader::FileLoader(const QString &filename)
{
    QFile file{filename};
    if (!file.exists())
        throw FileNotExistsException{};

    if (!file.open(QIODevice::ReadOnly))
        throw FileCannotOpenForRead{};

    QTextStream readingStream(&file);
    fileContent = readingStream.readAll();
    file.close();
}

QStringList GameBalda::FileLoader::contentList() const
{
    return fileContent.split("\r\n");
}
