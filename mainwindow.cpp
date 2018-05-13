#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    s = new Sudoku();

    boardInit();
    connect(ui->newGame, SIGNAL(clicked(bool)), this, SLOT(setBoardToggle()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::boardInit()
{
    printBoard();

    this->isSettingBoard = false;
    ui->board->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->messageBlock->insertHtml(*(new QString("<p>Initializing completed.<br/></p>")));
}

void MainWindow::printBoard()
{
    ui->board->clearSelection();
    for(int i=0; i<9; ++i)
    {
        for(int j=0; j<9; j++)
        {
            if(s->getElement(i, j) <= 0 || s->getElement(i, j) > 9)
            {
                ui->board->setItem(i, j, new QTableWidgetItem(*(new QString("")),0));
            }
            else
            {
                ui->board->setItem(i, j, new QTableWidgetItem(QString::number(s->getElement(i, j)),0));
            }
            QTableWidgetItem *theCell = ui->board->item(i, j);
            theCell->setTextAlignment(Qt::AlignCenter);
            if((i >= 0 && i<= 2) || (i >= 6 && i <= 8))
            {
                if((j >= 0 && j <= 2)||(j >= 6 && j <= 8))
                {
                    theCell->setBackgroundColor(*(new QColor(255,120,120)));
                }
            }
            else if(i >= 3 && i <= 5)
            {
                if(j >= 3 && j <= 5)
                {
                    theCell->setBackgroundColor(*(new QColor(255,120,120)));
                }
            }
        }
    }
}

void MainWindow::setBoard()
{
    s->setMap(*(ui->board));
    printBoard();
}

void MainWindow::setBoardToggle()
{
    if(this->isSettingBoard == false)
    {
        ui->board->setEditTriggers(QAbstractItemView::CurrentChanged|QAbstractItemView::DoubleClicked|QAbstractItemView::SelectedClicked);
        ui->newGame->setText("Solve !");
        ui->checking->setEnabled(false);
        ui->checking->setFlat(true);
        ui->answer->setEnabled(false);
        ui->answer->setFlat(true);
        this->isSettingBoard = true;
    }
    else
    {
        ui->board->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->newGame->setText("New Game");
        ui->checking->setEnabled(true);
        ui->checking->setFlat(false);
        ui->answer->setEnabled(true);
        ui->answer->setFlat(false);
        this->setBoard();
        this->isSettingBoard = false;
    }
}
