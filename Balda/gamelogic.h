#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <QStringList>
#include "matrix.h"

namespace GameBalda {

    class GameLogic {
    public:
        GameLogic(const QString & filename);
        QStringList findWordsList(const ClarensMath::Matrix<QChar> & arena) const;

    private:
        QStringList fileWords;
    };

}

#endif // GAMELOGIC_H
