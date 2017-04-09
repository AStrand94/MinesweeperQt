#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include <exception>
#include <QMediaPlayer>
#include "cell.h"

class MainWindow;

#include "difficulty.h"

using namespace diff;
class MineSweeper
{
public:
    MineSweeper(QGraphicsScene*,int bombCount, int rows, int columns, MainWindow* mainWindow);
    ~MineSweeper();
    void firstIsPressed(Cell*);
    void revealeAllBombs();
    void onCellMarked(bool);
    bool allBombsMarked();
    int getBombs();
    void checkIfWon();
    void playSound();

private:
    QMediaPlayer *player;
    QGraphicsScene *scene;
    int bombCount, rows, cols, size = 20;
    void createBlankGrid();
    Cell ***grid;
    Cell ** allBombs;
    void setNeighbours();
    void deleteGrid();
    void setBombsAround(Cell* cell);
    bool isBombsRevealed = false;
    bool bombsAreSet = false;
    MainWindow* mainWindow;
    Difficulty difficulty;

};

#endif // MINESWEEPER_H
