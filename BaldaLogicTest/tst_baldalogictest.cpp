#include <QString>
#include <QtTest>

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
    void testCorrectResult();
    void testFreeCellTrue();
    void testFreeCellFalse();
    void testNearIsLetterTrue();
    void testNearIsLetterFalse();
    void testCellInRangeTrue();
    void testCellInRangeFalse();
};

BaldaLogicTest::BaldaLogicTest()
{
    gameArena(2, 0) = 'Б';
    gameArena(2, 1) = 'А';
    gameArena(2, 2) = 'Л';
    gameArena(2, 3) = 'Д';
    gameArena(2, 4) = 'А';
}

void BaldaLogicTest::testCorrectResult()
{
    QStringList actualList = logic.findWordsList(gameArena);
    QStringList expectList{"ФАЛДА", ""};

    QCOMPARE(actualList, expectList);
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

QTEST_APPLESS_MAIN(BaldaLogicTest)

#include "tst_baldalogictest.moc"
