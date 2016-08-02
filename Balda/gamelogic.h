#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <QStringList>
#include "matrix.h"

class BaldaLogicTest;

namespace GameBalda {

    class GameLogic {
        friend BaldaLogicTest;
    public:
        GameLogic(const QString & filename);
        QStringList findWordsList(const ClarensMath::Matrix<QChar> & arena) const;

    private:
        bool isFreeCell(const ClarensMath::Matrix<QChar> & arena, int row, int col) const;

        QStringList fileWords;


    };

}

#endif // GAMELOGIC_H
