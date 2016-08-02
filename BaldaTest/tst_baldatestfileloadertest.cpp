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
};

BaldaTestFileLoaderTest::BaldaTestFileLoaderTest()
{

}

void BaldaTestFileLoaderTest::testFileNotExists()
{
    using GameBalda::FileLoader;

    QVERIFY_EXCEPTION_THROWN(FileLoader{"notexistsfile.txt"}, FileLoader::FileNotExistsException);
}

QTEST_APPLESS_MAIN(BaldaTestFileLoaderTest)

#include "tst_baldatestfileloadertest.moc"
