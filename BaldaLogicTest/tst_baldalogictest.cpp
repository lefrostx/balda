#include <QString>
#include <QtTest>
#include <vector>

#include "../Balda/matrix.h"
#include "../Balda/gamelogic.h"

class BaldaLogicTest : public QObject
{
    Q_OBJECT

public:
    BaldaLogicTest();

private:
    GameBalda::GameLogic logic{"baldafile.txt"};
    ClarensMath::Matrix<QChar> gameArena{5, 5, ' '};

private Q_SLOTS:
    void testFreeCellTrue();
    void testFreeCellFalse();
    void testNearIsLetterTrue();
    void testNearIsLetterFalse();
    void testCellInRangeTrue();
    void testCellInRangeFalse();
    void testCorrectResultList();
    void testCorrectResursionSearch();
};

BaldaLogicTest::BaldaLogicTest()
{
    gameArena(2, 0) = L'Б';
    gameArena(2, 1) = L'А';
    gameArena(2, 2) = L'Л';
    gameArena(2, 3) = L'Д';
    gameArena(2, 4) = L'А';
}

void BaldaLogicTest::testFreeCellTrue()
{
    QVERIFY(logic.isFreeCell(gameArena, 0, 0));
}

void BaldaLogicTest::testFreeCellFalse()
{
    QVERIFY(!logic.isFreeCell(gameArena, 2, 0));
}

void BaldaLogicTest::testNearIsLetterTrue()
{
    QVERIFY(logic.isNearLetter(gameArena, 1, 1));
}

void BaldaLogicTest::testNearIsLetterFalse()
{
    QVERIFY(!logic.isNearLetter(gameArena, 4, 2));
}

void BaldaLogicTest::testCellInRangeTrue()
{
    QVERIFY(logic.isInRange(gameArena, 1, 1));
}

void BaldaLogicTest::testCellInRangeFalse()
{
    QVERIFY(!logic.isInRange(gameArena, 5, 5));
}

void BaldaLogicTest::testCorrectResultList()
{
    using GameBalda::SearchResult;
    GameBalda::GameLogic logic{"baldafile.txt"};
    ClarensMath::Matrix<QChar> gameArena{5, 5, ' '};
    gameArena(2, 0) = L'Б';
    gameArena(2, 1) = L'А';
    gameArena(2, 2) = L'Л';
    gameArena(2, 3) = L'Д';
    gameArena(2, 4) = L'А';

    std::vector<SearchResult> actualList = logic.makeWordsList(gameArena);
    std::vector<SearchResult> expectList;

    expectList.push_back(SearchResult{L'А', {1, 0}, "АБА" });
    expectList.push_back(SearchResult{L'А', {3, 0}, "АБА" });

    QCOMPARE(actualList, expectList);
    logic.arena(1, 0)  = ' ';
}

void BaldaLogicTest::testCorrectResursionSearch()
{
    using GameBalda::SearchResult;
    GameBalda::GameLogic logic{"baldafile.txt"};
    ClarensMath::Matrix<QChar> gameArena{5, 5, ' '};
    gameArena(2, 0) = L'Б';
    gameArena(2, 1) = L'А';
    gameArena(2, 2) = L'Л';
    gameArena(2, 3) = L'Д';
    gameArena(2, 4) = L'А';
    gameArena(0, 4) = L'А';
    gameArena(1, 4) = L'Б';
    gameArena(3, 4) = L'Р';
    logic.arena = gameArena;
    logic.bindingCell = ClarensMath::Cell{0, 4};

    logic.recursionSearch({2, 4}, "");
    std::vector<SearchResult> actualList = logic.resultList;
    std::vector<SearchResult> expectList;

    expectList.push_back(SearchResult{L'А', {0, 4}, "АБА" });

    QCOMPARE(actualList, expectList);
    logic.arena(1, 0)  = ' ';
}

QTEST_APPLESS_MAIN(BaldaLogicTest)

#include "tst_baldalogictest.moc"
