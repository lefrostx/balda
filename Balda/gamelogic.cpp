#include "gamelogic.h"
#include "fileloader.h"

GameBalda::GameLogic::GameLogic(const QString &filename) :
    fileWords{FileLoader{filename}.contentList()}
{
}

QStringList GameBalda::GameLogic::findWordsList(const ClarensMath::Matrix<QChar> &arena) const
{
    QStringList lst{"ФАЛДА", ""};
    return lst;
}
