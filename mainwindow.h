#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include <QTableWidget>
#include <QVector>
#include <QString>
#include <QBrush>
#include <QAbstractItemView>

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

    void boardInit();
    void printBoard();
    void setBoard();


    ~MainWindow();

private slots:
    void setBoardToggle();

private:
    Ui::MainWindow *ui;
    Sudoku *s;

    bool isSettingBoard;
};

#endif // MAINWINDOW_H
