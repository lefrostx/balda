#include <QString>
#include <QtTest>

class BaldaLogicTest : public QObject
{
    Q_OBJECT

public:
    BaldaLogicTest();

private Q_SLOTS:
    void testCase1();
};

BaldaLogicTest::BaldaLogicTest()
{
}

void BaldaLogicTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(BaldaLogicTest)

#include "tst_baldalogictest.moc"
