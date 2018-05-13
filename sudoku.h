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
    void clearMap();
    int getElement(int row, int column);
    void solveSudoku(QTextBrowser *msg, QTableWidget *board);
    bool isCorrect();
    bool isFull();
    bool isEmpty();
    bool isProperMap();
    bool canBeSolved;


private:
    int map[9][9];
    bool checkingUnity(const QVector<int> &a);

    /*Solve Area*/
    QVector<bool> getPossibleVector(int x, int y);
    void setElement(int row, int column, int value);
};

#endif // SUDOKU_H
