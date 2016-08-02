#include <QString>
#include <QtTest>

class BaldaTestLogicTest : public QObject
{
    Q_OBJECT

public:
    BaldaTestLogicTest();

private Q_SLOTS:
    void testCase1();
};

BaldaTestLogicTest::BaldaTestLogicTest()
{
}

void BaldaTestLogicTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(BaldaTestLogicTest)

#include "tst_baldatestlogictest.moc"
