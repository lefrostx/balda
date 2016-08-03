#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <vector>
#include <QStringList>
#include "matrix.h"

class BaldaLogicTest;

namespace GameBalda {

    struct SearchResult {
        QChar letter;
        ClarensMath::Cell cell;
        QString word;
    };

    inline bool operator == (const SearchResult& lhs, const SearchResult& rhs)
    {
        return lhs.letter == rhs.letter && lhs.cell == rhs.cell && lhs.word == rhs.word;
    }

    inline bool operator != (const SearchResult& lhs, const SearchResult& rhs)
    {
        return !(lhs == rhs);
    }

    class GameLogic {
        friend BaldaLogicTest;
    public:
        GameLogic(const QString & filename);
        std::vector<SearchResult> makeWordsList(const ClarensMath::Matrix<QChar> & gameArena);
        QStringList findWordsList(const ClarensMath::Matrix<QChar> & arena) const;

    private:
        void recursionSearch(ClarensMath::Cell cell, const QString & path);
        bool isFreeCell(const ClarensMath::Matrix<QChar> & arena, int row, int col) const;
        bool isLetterCell(const ClarensMath::Matrix<QChar> & arena, int row, int col) const;
        bool isNearLetter(const ClarensMath::Matrix<QChar> & arena, int row, int col) const;
        bool isInRange(const ClarensMath::Matrix<QChar> & arena, int row, int col) const;

        QStringList fileWords;
        std::vector<SearchResult> resultList;
        ClarensMath::Matrix<QChar> arena{5, 5, ' '};
        ClarensMath::Matrix<bool> usedArena{5, 5, false};
        ClarensMath::Cell bindingCell;
        bool usedBindingCell{false};
    };

}

#endif // GAMELOGIC_H
