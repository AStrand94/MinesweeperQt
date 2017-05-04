#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include <exception>
#include <QMediaPlayer>
#include "cell.h"

class MainWindow;
class MineSweeper
{
public:
    MineSweeper(QGraphicsScene*,int bombCount, int rows, int columns, int cellSize, MainWindow* mainWindow);
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
    MainWindow* mainWindow;

};

#endif // MINESWEEPER_H
