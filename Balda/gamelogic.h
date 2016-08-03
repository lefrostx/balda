#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <vector>
#include <set>
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
        return lhs.word == rhs.word;
    }

    inline bool operator != (const SearchResult& lhs, const SearchResult& rhs)
    {
        return !(lhs == rhs);
    }

    inline bool operator < (const SearchResult& lhs, const SearchResult& rhs)
    {
        if (lhs.word.length() > rhs.word.length())
            return true;
        else if (lhs.word.length() == rhs.word.length())
            return lhs.word < rhs.word;
        else return false;
    }

    class GameLogic {
        friend BaldaLogicTest;
    public:
        GameLogic(const QString & filename);
        std::vector<SearchResult> makeWordsList(const ClarensMath::Matrix<QChar> & gameArena);

    private:
        void recursionSearch(ClarensMath::Cell cell, const QString & path);
        bool isFreeCell(const ClarensMath::Matrix<QChar> & arena, int row, int col) const;
        bool isLetterCell(const ClarensMath::Matrix<QChar> & arena, int row, int col) const;
        bool isNearLetter(const ClarensMath::Matrix<QChar> & arena, int row, int col) const;
        bool isInRange(const ClarensMath::Matrix<QChar> & arena, int row, int col) const;
        bool prefixExists(const QString& word);

        std::set<QString> fileWords;
        std::vector< std::set<QString> > prefixes;
        std::vector<SearchResult> resultList;
        ClarensMath::Matrix<QChar> arena{5, 5, ' '};
        ClarensMath::Matrix<bool> usedArena{5, 5, false};
        ClarensMath::Cell bindingCell;
        bool usedBindingCell{false};
        static const int maxPrefixLength = 10;
    };

}

#endif // GAMELOGIC_H
