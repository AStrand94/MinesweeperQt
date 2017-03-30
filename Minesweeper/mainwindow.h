#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include <QDialog>
#include <QGraphicsScene>
#include "cell.h"
#include "minesweeper.h"
//#include "difficulty.h"

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

    void startTime();
    void decreaseBombDisplayCount();
    void increaseBombDisplayCount();



private slots:
    void updateTimer();
    void on_clearButton_clicked();

private:
    int rows, cols, size,bombs;
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    MineSweeper *game;
    void createNewGame(int width, int height, int bombs);
     QTimer* timer;
     int seconds;
     void displayTime(int time);
     int bombDisplayCount;
     void displayBombCount(int bombs);
     void setGameValuesToEasy();
     void setGameValuesToMedium();
     void setGameValuesToHard();
     bool allBombsMarked();
};

#endif // MAINWINDOW_H
