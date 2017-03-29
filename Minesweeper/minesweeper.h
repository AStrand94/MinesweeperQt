#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include <exception>
#include "cell.h"
class MainWindow;

class MineSweeper
{
public:
    MineSweeper(QGraphicsScene*,int bombCount, int rows, int columns, MainWindow* mainWindow);
    ~MineSweeper();
    void firstIsPressed(Cell*);
    void revealeAllBombs();
    void onCellMarked(bool);

private:
    QGraphicsScene *scene;
    int bombCount, rows, cols, size = 25;
    void createBlankGrid();
    Cell ***grid;
    Cell ** allBombs;
    void setNeighbours();
    void deleteGrid();
    void setBombsAround(Cell* cell);
    bool isBombsRevealed = false;
    MainWindow* mainWindow;

};

#endif // MINESWEEPER_H
