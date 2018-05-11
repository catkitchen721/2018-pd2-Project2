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
            map[i][j] = board.item(i, j)->text().toInt();
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
