#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Sudoku *s;
    s = new Sudoku();

    boardInit(s);
    connect(ui->newGame, SIGNAL(clicked(bool)), this, SLOT(setBoardEnable()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::boardInit(Sudoku *s)
{
    for(int i=0; i<9; ++i)
    {
        for(int j=0; j<9; j++)
        {
            ui->board->setItem(i, j, new QTableWidgetItem(QString::number(s->getElement(i, j)),0));
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

    ui->board->setEnabled(false);
    ui->messageBlock->insertHtml(*(new QString("<p>Initializing completed.<br/></p>")));
}

void MainWindow::printBoard(Sudoku *s)
{
    for(int i=0; i<9; ++i)
    {
        for(int j=0; j<9; ++j)
        {
            ui->board->setItem(i, j, new QTableWidgetItem(QString::number(s->getElement(i, j)),0));
        }
    }
}

void MainWindow::setBoard(Sudoku *s)
{
    s->setMap(*(ui->board));
    printBoard(s);
}

void MainWindow::setBoardEnable()
{
    ui->board->setEnabled(true);
}
