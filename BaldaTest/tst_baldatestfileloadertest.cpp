#include <QString>
#include <QtTest>

#include "../Balda/fileloader.h"

class BaldaTestFileLoaderTest : public QObject
{
    Q_OBJECT

public:
    BaldaTestFileLoaderTest();

private Q_SLOTS:
    void testFileNotExists();
    void testFileCanOpenForRead();
    void testFileCorrectReading();
};

BaldaTestFileLoaderTest::BaldaTestFileLoaderTest()
{

}

void BaldaTestFileLoaderTest::testFileNotExists()
{
    using GameBalda::FileLoader;

    QVERIFY_EXCEPTION_THROWN(FileLoader{"notexistsfile.txt"}, FileLoader::FileNotExistsException);
}

void BaldaTestFileLoaderTest::testFileCanOpenForRead()
{
    using GameBalda::FileLoader;

    QVERIFY_EXCEPTION_THROWN(FileLoader{"notforreadfile.txt"}, FileLoader::FileCannotOpenForRead);
}

void BaldaTestFileLoaderTest::testFileCorrectReading()
{
    using GameBalda::FileLoader;

    FileLoader loader{"testfile.txt"};
    QStringList expectingList{"first", "second", "third"};
    QStringList actualList = loader.content();

    QCOMPARE(actualList, expectingList);
}

QTEST_APPLESS_MAIN(BaldaTestFileLoaderTest)

#include "tst_baldatestfileloadertest.moc"
