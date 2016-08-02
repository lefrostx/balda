#include <QString>
#include <QtTest>

class BaldaTestFileLoaderTest : public QObject
{
    Q_OBJECT

public:
    BaldaTestFileLoaderTest();

private Q_SLOTS:
    void testCase1();
};

BaldaTestFileLoaderTest::BaldaTestFileLoaderTest()
{
}

void BaldaTestFileLoaderTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(BaldaTestFileLoaderTest)

#include "tst_baldatestfileloadertest.moc"
