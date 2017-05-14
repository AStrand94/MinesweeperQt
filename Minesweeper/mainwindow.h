#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include <QDialog>
#include <QGraphicsScene>
#include "cell.h"
#include "minesweeper.h"
#include <highscore.h>
#include <qmessagebox.h>
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

    void enablePauseButton(bool);
    bool immortal;


private slots:
    void updateTimer();
    void on_clearButton_clicked();
    void on_highscoreButton_clicked();
    void on_pauseButton_clicked();
    void on_gamePauseShortcutPressed();
    void on_actionMute_triggered();
    void on_actionImmortal_triggered();
    void on_actionGame_Rules_and_Controls_triggered();
    void setButtonText(int);

    void decreaseBombDisplayCount();
    void increaseBombDisplayCount();
    void addToTimer(int);
    void gameFinished(bool);
    void startTime();

private:
    Highscore highscore;
    int rows, cols, size,bombs, cellSize;
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
    void setHighScore();
    bool chooseNewGame();
    void setupConnections();
};

#endif // MAINWINDOW_H
