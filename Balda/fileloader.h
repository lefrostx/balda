#ifndef FILELOADER_H
#define FILELOADER_H

#include <QString>

namespace GameBalda {

    class FileLoader {
    public:
        class FileNotExistsException {};

        FileLoader(const QString & filename);
    };

}

#endif // FILELOADER_H
