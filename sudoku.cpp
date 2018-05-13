#include "sudoku.h"


Sudoku::Sudoku()
{
    for(int i=0;i<9;++i)
    {
        for(int j=0;j<9;j++)
        {
            map[i][j] = 0;
        }
    }
}

void Sudoku::setMap(const QTableWidget &board)
{
    for(int i=0;i<9;++i)
    {
        for(int j=0;j<9;j++)
        {
            if(board.item(i, j)->text().toInt() <= 0 || board.item(i, j)->text().toInt() > 9)
            {
                map[i][j] = 0;
            }
            else
            {
                map[i][j] = board.item(i, j)->text().toInt();
            }
        }
    }
}

int Sudoku::getElement(int row, int column)
{
    return map[row][column];
}

bool Sudoku::isCorrect()
{
    return false;
}

bool Sudoku::checkingUnity(const int a[])
{
    return false;
}

void Sudoku::solveSudoku(QTextBrowser *msg, QTableWidget *board)
{
    int x = 0, y = 0;

    QVector<bool> posV(10);

    if(isFull())
    {
        msg->insertHtml("<p>Solving progress completed.<br/></p>");
        this->canBeSolved = true;
        //
        board->clearSelection();
        for(int i=0; i<9; ++i)
        {
            for(int j=0; j<9; j++)
            {
                if(this->getElement(i, j) <= 0 || this->getElement(i, j) > 9)
                {
                    board->setItem(i, j, new QTableWidgetItem(*(new QString("")),0));
                }
                else
                {
                    board->setItem(i, j, new QTableWidgetItem(QString::number(this->getElement(i, j)),0));
                }
                QTableWidgetItem *theCell = board->item(i, j);
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
        //
        return;
    }
    else
    {
        bool isBreak = false;
        for(int i=0; i<9; ++i)
        {
            for(int j=0; j<9; ++j)
            {
                if(this->getElement(i, j) == 0)
                {
                    x = i;
                    y = j;
                    isBreak = true;
                    break;
                }
            }
            if(isBreak == true) break;
        }

        posV = this->getPossibleVector(x, y);

        for(int i=1; i<=9; ++i)
        {
            if(posV.at(i) == true)
            {
                this->setElement(x, y, i);
                this->solveSudoku(msg, board);
            }
        }
        this->setElement(x, y, 0);
    }
}

bool Sudoku::isFull()
{
    for(int i=0; i<9; ++i)
    {
        for(int j=0; j<9; ++j)
        {
            if(this->getElement(i, j) == 0) return false;
        }
    }
    return true;
}

QVector<bool> Sudoku::getPossibleVector(int x, int y)
{
    QVector<bool> posV(10);

    for(int i=1; i<=9; ++i)
    {
        posV.replace(i,true);
    }

    for(int j=0; j<9; ++j)
    {
        if(this->map[x][j] != 0)
        {
            posV.replace(this->map[x][j], false);
        }
    }

    for(int i=0; i<9; ++i)
    {
        if(this->map[i][y] != 0)
        {
            posV.replace(this->map[i][y], false);
        }
    }

    int sqrI = 0;
    int sqrJ = 0;

    if(x >= 0 && x <= 2)
    {
        sqrI = 0;
    }
    else if(x >= 3 && x <= 5)
    {
        sqrI = 3;
    }
    else
    {
        sqrI = 6;
    }

    if(y >= 0 && y <= 2)
    {
        sqrJ = 0;
    }
    else if(y >= 3 && y <= 5)
    {
        sqrJ = 3;
    }
    else
    {
        sqrJ = 6;
    }

    for(int i=sqrI; i<sqrI+3; ++i)
    {
        for(int j=sqrJ; j<sqrJ+3; ++j)
        {
            if(this->map[i][j] != 0)
            {
                posV.replace(this->map[i][j], false);
            }
        }
    }

    return posV;
}

void Sudoku::setElement(int row, int column, int value)
{
    this->map[row][column] = value;
}
