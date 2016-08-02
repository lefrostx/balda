#include "gamelogic.h"
#include "fileloader.h"

GameBalda::GameLogic::GameLogic(const QString &filename) :
    fileWords{FileLoader{filename}.contentList()}
{
}

QStringList GameBalda::GameLogic::findWordsList(const ClarensMath::Matrix<QChar> &arena) const
{
    for (int row = 0; row < arena.rows(); ++row) {
        for (int col = 0; col < arena.cols(); ++col) {

        }
    }


    QStringList lst{"ФАЛДА", ""};
    return lst;
}

bool GameBalda::GameLogic::isFreeCell(const ClarensMath::Matrix<QChar> &arena, int row, int col) const
{
    if (row < 0 || row >= arena.rows())
        return false;

    if (col < 0 || col >= arena.cols())
        return false;

    return arena(row, col) == ' ';
}
