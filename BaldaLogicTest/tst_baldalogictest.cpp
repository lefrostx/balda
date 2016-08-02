#include <QString>
#include <QtTest>

#include "../Balda/matrix.h"
#include "../Balda/gamelogic.h"

class BaldaLogicTest : public QObject
{
    Q_OBJECT

public:
    BaldaLogicTest();

private Q_SLOTS:
    void testCorrectResult();
};

BaldaLogicTest::BaldaLogicTest()
{
}

void BaldaLogicTest::testCorrectResult()
{
    using GameBalda::GameLogic;

    ClarensMath::Matrix<QChar> gameArena{5, 5, ' '};
    gameArena(2, 0) = 'Б';
    gameArena(2, 1) = 'А';
    gameArena(2, 2) = 'Л';
    gameArena(2, 3) = 'Д';
    gameArena(2, 4) = 'А';

    GameLogic logic{"baldafile.txt"};
    QStringList actualList = logic.findWordsList(gameArena);
    QStringList expectList{"ФАЛДА", ""};

    QCOMPARE(actualList, expectList);
}

QTEST_APPLESS_MAIN(BaldaLogicTest)

#include "tst_baldalogictest.moc"
