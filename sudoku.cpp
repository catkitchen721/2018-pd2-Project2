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

bool Sudoku::solveSudoku()
{
    return false;


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
        posV.insert(i,true);
    }

    for(int j=0; j<9; ++j)
    {
        if(this->map[x][j] != 0)
        {
            posV.insert(this->map[x][j], false);
        }
    }

    for(int i=0; i<9; ++i)
    {
        if(this->map[i][y] != 0)
        {
            posV.insert(this->map[i][y], false);
        }
    }



    return posV;
}
