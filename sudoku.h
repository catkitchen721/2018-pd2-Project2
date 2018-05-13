#ifndef SUDOKU_H
#define SUDOKU_H

#include <QTableWidget>
#include <QTableWidgetItem>
#include <QTextBrowser>
#include <QString>
#include <QVector>

using namespace std;

class Sudoku
{
public:
    Sudoku();
    void setMap(const QTableWidget &board);
    int getElement(int row, int column);
    bool canBeSolved;
    bool isCorrect();
    void solveSudoku(QTextBrowser *msg, QTableWidget *board);


private:
    int map[9][9];
    bool checkingUnity(const int a[]);

    /*Solve Area*/
    bool isFull();
    QVector<bool> getPossibleVector(int x, int y);
    void setElement(int row, int column, int value);
};

#endif // SUDOKU_H
