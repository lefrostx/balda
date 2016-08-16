#include "gamelogic.h"
#include "fileloader.h"

GameBalda::GameLogic::GameLogic(const QString &filename) :
    prefixes(maxPrefixLength)
{
    QStringList lst = FileLoader{filename}.content();

    for (int i = 0; i < maxPrefixLength; ++i) {
        int prefixLength = i + 1;
        for (const auto & x : lst) {
            if (x.size() >= prefixLength)
                prefixes[i].insert(x.left(prefixLength));
        }
    }

    for (const auto & x : lst)
        fileWords.insert(x);
}

QVector<GameBalda::SearchResult> GameBalda::GameLogic::makeWordsList(const ClarensMath::Matrix<QChar> &gameArena)
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
                    findWords();
                    arena[bindingCell] = L' ';
                }
            }
        }
    }

    std::sort(resultList.begin(), resultList.end());
    auto uniqueEndIter = std::unique(resultList.begin(), resultList.end());
    resultList.resize(std::distance(resultList.begin(), uniqueEndIter));

    return resultList;
}

void GameBalda::GameLogic::search(ClarensMath::Cell cell, QString path)
{
    if (!isLetterCell(arena, cell.row, cell.col))
        return;

    if (usedArena[cell])
        return;

    path += arena[cell];

    if (!prefixExists(path))
        return;

    if (cell == bindingCell)
        usedBindingCell = true;

    usedArena[cell] = true;

    if (usedBindingCell && fileWords.contains(path)) {
        resultList.push_back({arena[bindingCell], bindingCell, path});
    }

    search(ClarensMath::Cell{cell.row - 1, cell.col}, path);
    search(ClarensMath::Cell{cell.row + 1, cell.col}, path);
    search(ClarensMath::Cell{cell.row, cell.col - 1}, path);
    search(ClarensMath::Cell{cell.row, cell.col + 1}, path);

    usedArena[cell] = false;
    if (cell == bindingCell)
        usedBindingCell = false;
}

void GameBalda::GameLogic::findWords()
{
    for (int row = 0; row < arena.rows(); ++row)
        for (int col = 0; col < arena.cols(); ++col) {
            usedBindingCell = false;
            search(ClarensMath::Cell{row, col}, "");
        }
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

    return prefixes[word.size() - 1].contains(word);
}
