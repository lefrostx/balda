#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    logic{"slova.txt"}
{
    ui->setupUi(this);
    for (int row = 0; row < 5; ++row)
        for (int col = 0; col < 5; ++col) {
            QTableWidgetItem *newItem = new QTableWidgetItem(" ");
            ui->gameTable->setItem(row, col, newItem);
        }
    ui->gameTable->item(2, 0)->setText("Б");
    ui->gameTable->item(2, 1)->setText("А");
    ui->gameTable->item(2, 2)->setText("Л");
    ui->gameTable->item(2, 3)->setText("Д");
    ui->gameTable->item(2, 4)->setText("А");

    connect(ui->searchStartButton, SIGNAL(clicked(bool)), SLOT(findWords()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::findWords()
{
    ClarensMath::Matrix<QChar> gameArena{5, 5, ' '};
    for (int row = 0; row < 5; ++row)
        for (int col = 0; col < 5; ++col) {
            QChar letter = ui->gameTable->item(row, col)->text()[0];
            gameArena(row, col) = letter;
        }
    auto result = logic.makeWordsList(gameArena);
    QString words;
    for (auto x : result) {
        words += QString(x.letter) + "\t" + QString::number(x.cell.row) + " " + QString::number(x.cell.col) + "\t"  + x.word + "\n";
    }
    ui->foundWordsText->setText(words);
}
