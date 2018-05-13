#ifndef SUDOKU_H
#define SUDOKU_H

#include <QTableWidget>
#include <QTableWidgetItem>
#include <QString>
#include <QVector>

using namespace std;

class Sudoku
{
public:
    Sudoku();
    void setMap(const QTableWidget &board);
    int getElement(int row, int column);
    bool isCorrect();
    bool solveSudoku();


private:
    int map[9][9];
    bool checkingUnity(const int a[]);

    /*Solve Area*/
    bool isFull();
    QVector<bool> getPossibleVector(int x, int y);
};

#endif // SUDOKU_H
