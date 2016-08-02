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

private Q_SLOTS:
    void testCorrectResult();
    void testFreeCell();
};

BaldaLogicTest::BaldaLogicTest()
{
}

void BaldaLogicTest::testCorrectResult()
{
    ClarensMath::Matrix<QChar> gameArena{5, 5, ' '};
    gameArena(2, 0) = 'Б';
    gameArena(2, 1) = 'А';
    gameArena(2, 2) = 'Л';
    gameArena(2, 3) = 'Д';
    gameArena(2, 4) = 'А';

    QStringList actualList = logic.findWordsList(gameArena);
    QStringList expectList{"ФАЛДА", ""};

    QCOMPARE(actualList, expectList);
}

void BaldaLogicTest::testFreeCell()
{
    ClarensMath::Matrix<QChar> gameArena{5, 5, ' '};
    gameArena(2, 0) = 'Б';
    gameArena(2, 1) = 'А';
    gameArena(2, 2) = 'Л';
    gameArena(2, 3) = 'Д';
    gameArena(2, 4) = 'А';

    QVERIFY(logic.isFreeCell(gameArena, 0, 0));
}

QTEST_APPLESS_MAIN(BaldaLogicTest)

#include "tst_baldalogictest.moc"
