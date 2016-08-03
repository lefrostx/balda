#include <algorithm>
#include <set>
#include "gamelogic.h"
#include "fileloader.h"

GameBalda::GameLogic::GameLogic(const QString &filename) :
    prefixes(maxPrefixLength)
{
    QStringList lst = FileLoader{filename}.contentList();

    for (int i = 0; i < maxPrefixLength; ++i) {
        int length = i + 1;
        for (const auto & x : lst) {
            if (x.size() >= length)
                prefixes[i].insert(x.left(length));
        }
    }

    fileWords.insert(lst.begin(), lst.end());
}

std::vector<GameBalda::SearchResult> GameBalda::GameLogic::makeWordsList(const ClarensMath::Matrix<QChar> &gameArena)
{
    arena = gameArena;
    resultList.clear();
    QString alphabet = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЧШЩЪЫЬЭЮЯ";
    for (int row = 0; row < arena.rows(); ++row) {
        for (int col = 0; col < arena.cols(); ++col) {
            if (isFreeCell(arena, row, col) && isNearLetter(arena, row, col)) {
                bindingCell = ClarensMath::Cell{row, col};
                for (auto x : alphabet) {
                    arena[bindingCell] = x;
                    for (int rw = 0; rw < arena.rows(); ++rw)
                        for (int cl = 0; cl < arena.cols(); ++cl) {
                            usedBindingCell = false;
                            recursionSearch(ClarensMath::Cell{rw, cl}, "");
                        }
                    arena[bindingCell] = L' ';
                }
            }
        }
    }

    std::set<SearchResult> tempSet{resultList.begin(), resultList.end()};

    return std::vector<SearchResult>{tempSet.begin(), tempSet.end()};
}

void GameBalda::GameLogic::recursionSearch(ClarensMath::Cell cell, const QString &path)
{
    if (!isLetterCell(arena, cell.row, cell.col))
        return;

    if (usedArena[cell])
        return;

    QString newPath = path + arena[cell];

    if (!prefixExists(newPath))
        return;

    if (cell == bindingCell)
        usedBindingCell = true;

    usedArena[cell] = true;

    if (usedBindingCell && fileWords.find(newPath) != fileWords.end()) {
        resultList.push_back({arena[bindingCell], bindingCell, newPath});
    }

    recursionSearch(ClarensMath::Cell{cell.row - 1, cell.col}, newPath);
    recursionSearch(ClarensMath::Cell{cell.row + 1, cell.col}, newPath);
    recursionSearch(ClarensMath::Cell{cell.row, cell.col - 1}, newPath);
    recursionSearch(ClarensMath::Cell{cell.row, cell.col + 1}, newPath);

    usedArena[cell] = false;
    if (cell == bindingCell)
        usedBindingCell = false;
}

bool GameBalda::GameLogic::isFreeCell(const ClarensMath::Matrix<QChar> &arena, int row, int col) const
{
    return isInRange(arena, row, col) && arena(row, col) == L' ';
}

bool GameBalda::GameLogic::isLetterCell(const ClarensMath::Matrix<QChar> &arena, int row, int col) const
{
    return isInRange(arena, row, col) && arena(row, col) != L' ';
}

bool GameBalda::GameLogic::isNearLetter(const ClarensMath::Matrix<QChar> &arena, int row, int col) const
{
    if (isInRange(arena, row - 1, col) && arena(row - 1, col) != L' ')
        return true;

    if (isInRange(arena, row, col - 1) && arena(row, col - 1) != L' ')
        return true;

    if (isInRange(arena, row + 1, col) && arena(row + 1, col) != L' ')
        return true;

    if (isInRange(arena, row, col + 1) && arena(row, col + 1) != L' ')
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

bool GameBalda::GameLogic::prefixExists(const QString &word)
{
    if (word.size() > maxPrefixLength)
        return true;

    return prefixes[word.size() - 1].find(word) != prefixes[word.size() - 1].end();
}
