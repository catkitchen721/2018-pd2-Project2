#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include <QTableWidget>
#include <QVector>
#include <QString>
#include <QBrush>

#include "sudoku.h"

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    void boardInit(Sudoku *s);
    void printBoard(Sudoku *s);
    void setBoard(Sudoku *s);


    ~MainWindow();

private slots:
    void setBoardEnable();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
