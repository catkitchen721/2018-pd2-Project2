#ifndef SUDOKU_H
#define SUDOKU_H

#include <QTableWidget>
#include <QTableWidgetItem>
#include <QString>

using namespace std;

class Sudoku
{
public:
    Sudoku();
    void setMap(const QTableWidget &board);
    int getElement(int row, int column);
    bool isCorrect();

private:
    int map[9][9];
    bool checkingUnity(const int a[]);
};

#endif // SUDOKU_H
