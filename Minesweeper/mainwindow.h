#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include <QDialog>
#include <QGraphicsScene>
#include "cell.h"
#include "minesweeper.h"

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:

    void on_clearButton_clicked();

private:
    int rows, cols, size,bombs;
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    MineSweeper *game;
    void createNewGame(int width, int height, int bombs);
};

#endif // MAINWINDOW_H
