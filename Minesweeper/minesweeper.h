#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include <exception>
#include "cell.h"

class MineSweeper
{
public:
    MineSweeper(QGraphicsScene*,int bombCount, int rows, int columns);
    ~MineSweeper();
    void firstIsPressed(Cell*);
    void revealeAllBombs();

private:
    QGraphicsScene *scene;
    int bombCount, rows, cols, size = 15;
    void createBlankGrid();
    Cell ***grid;
    Cell ** allBombs;
    void setNeighbours();
    void deleteGrid();
    void setBombsAround(Cell* cell);

};

#endif // MINESWEEPER_H
