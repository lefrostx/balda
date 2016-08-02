#include "gamelogic.h"
#include "fileloader.h"

GameBalda::GameLogic::GameLogic(const QString &filename) :
    fileWords{FileLoader{filename}.contentList()}
{
}

QStringList GameBalda::GameLogic::findWordsList(const ClarensMath::Matrix<QChar> &arena) const
{
    QString alphabet = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЧШЩЪЫЬЭЮЯ";
    for (int row = 0; row < arena.rows(); ++row) {
        for (int col = 0; col < arena.cols(); ++col) {
            if (isFreeCell(arena, row, col)) {
                for (auto x : alphabet) {

                }
            }
        }
    }

    QStringList lst{"ФАЛДА", ""};
    return lst;
}

bool GameBalda::GameLogic::isFreeCell(const ClarensMath::Matrix<QChar> &arena, int row, int col) const
{
    return isInRange(arena, row, col) && arena(row, col) == ' ';
}

bool GameBalda::GameLogic::isNearLetter(const ClarensMath::Matrix<QChar> &arena, int row, int col) const
{
    if (isInRange(arena, row - 1, col) && arena(row - 1, col) != ' ')
        return true;

    if (isInRange(arena, row, col - 1) && arena(row, col - 1) != ' ')
        return true;

    if (isInRange(arena, row + 1, col) && arena(row + 1, col) != ' ')
        return true;

    if (isInRange(arena, row, col + 1) && arena(row, col + 1) != ' ')
        return true;

    return false;
}

bool GameBalda::GameLogic::isInRange(const ClarensMath::Matrix<QChar> &arena, int row, int col) const
{
    if (row < 0 || row >= arena.rows())
        return false;

    if (col < 0 || col >= arena.cols())
        return false;

    return true;
}
