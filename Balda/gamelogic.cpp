#include <algorithm>
#include "gamelogic.h"
#include "fileloader.h"

GameBalda::GameLogic::GameLogic(const QString &filename) :
    fileWords{FileLoader{filename}.contentList()}
{
}

std::vector<GameBalda::SearchResult> GameBalda::GameLogic::makeWordsList(const ClarensMath::Matrix<QChar> &gameArena)
{
    arena = gameArena;
    QString alphabet = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЧШЩЪЫЬЭЮЯ";
    for (int row = 0; row < arena.rows(); ++row) {
        for (int col = 0; col < arena.cols(); ++col) {
            if (isFreeCell(arena, row, col) && isNearLetter(arena, row, col)) {
                bindingCell = ClarensMath::Cell{row, col};
                for (auto x : alphabet) {
                    arena[bindingCell] = x;
                    for (int rw = 0; rw < arena.rows(); ++rw)
                        for (int cl = 0; cl < arena.cols(); ++cl) {
                            std::fill(usedArena.begin(), usedArena.end(), false);
                            usedBindingCell = false;
                            recursionSearch(ClarensMath::Cell{rw, cl}, "");
                        }
                    arena[bindingCell] = ' ';
                }
            }
        }
    }

    auto iter = std::unique(resultList.begin(), resultList.end());
    resultList.resize(std::distance(resultList.begin(), iter));
    std::sort(resultList.begin(), resultList.end());
    std::reverse(resultList.begin(), resultList.end());

    return resultList;
}

void GameBalda::GameLogic::recursionSearch(ClarensMath::Cell cell, const QString &path)
{
    if (!isLetterCell(arena, cell.row, cell.col))
        return;

    if (usedArena[cell])
        return;

    if (cell == bindingCell)
        usedBindingCell = true;

    usedArena[cell] = true;

    QChar letter = arena[cell];
    QString newPath = path + letter;
    if (usedBindingCell && fileWords.contains(newPath)) {
        resultList.push_back({letter, bindingCell, newPath});
        usedBindingCell = false;
    }

    recursionSearch(ClarensMath::Cell{cell.row - 1, cell.col}, newPath);
    recursionSearch(ClarensMath::Cell{cell.row + 1, cell.col}, newPath);
    recursionSearch(ClarensMath::Cell{cell.row, cell.col - 1}, newPath);
    recursionSearch(ClarensMath::Cell{cell.row, cell.col + 1}, newPath);

    usedArena[cell] = false;
}

bool GameBalda::GameLogic::isFreeCell(const ClarensMath::Matrix<QChar> &arena, int row, int col) const
{
    return isInRange(arena, row, col) && arena(row, col) == ' ';
}

bool GameBalda::GameLogic::isLetterCell(const ClarensMath::Matrix<QChar> &arena, int row, int col) const
{
    return isInRange(arena, row, col) && arena(row, col) != ' ';
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
