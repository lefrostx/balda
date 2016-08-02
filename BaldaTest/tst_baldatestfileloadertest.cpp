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

QTEST_APPLESS_MAIN(BaldaTestFileLoaderTest)

#include "tst_baldatestfileloadertest.moc"
