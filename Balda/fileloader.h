#ifndef FILELOADER_H
#define FILELOADER_H

#include <QStringList>

namespace GameBalda {

    class FileLoader {
    public:
        class FileNotExistsException {};
        class FileCannotOpenForRead {};

        FileLoader(const QString & filename);
        QStringList contentList() const;
    private:
        QString fileContent;
    };

}

#endif // FILELOADER_H
