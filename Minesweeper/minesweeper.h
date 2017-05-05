#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include <exception>
#include <QMediaPlayer>
#include "cell.h"


class MineSweeper : public QObject
{
Q_OBJECT

public:
    MineSweeper(QGraphicsScene*,int bombCount, int rows, int columns, int cellSize);
    ~MineSweeper();
    void firstIsPressed(Cell*);
    void revealeAllBombs();
    void onCellMarked(bool);
    bool allBombsMarked();
    int getBombs();
    void checkIfWon();
    void playSound();
    void setVolume(int);
    void setImmortalMode(bool);
    bool getImmortalMode();
    void updateTimer(int);
    void decreaseBombDisplayCount();

signals:
    void bombMarked();
    void bombUnMarked();
    void addToTimer(int);
    void gameOver(bool);
    void gameStarted();

private:
    QMediaPlayer *player;
    QGraphicsScene *scene;
    int bombCount, rows, cols, size;
    bool immortalMode;
    void createBlankGrid();
    Cell ***grid;
    Cell ** allBombs;
    void setNeighbours();
    void deleteGrid();
    void setBombsAround(Cell* cell);
    bool isBombsRevealed = false;
    bool bombsAreSet = false;
};

#endif // MINESWEEPER_H
