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
    MineSweeper(QGraphicsScene*,int bombs, int rows, int columns, int cellsize);
    ~MineSweeper();
    void firstIsPressed(Cell*);


private:
    QGraphicsScene *scene;
    int bombs, rows, cols, size;
    void createGrid();
    Cell ***grid;
    void setBombs(int x);
    Cell ** allBombs;
    void setNeighbourBombs();
    void setInform();
    int getBombs(int x, int y);
    void deleteGrid();
    void clearBombs();
    void setCellBombsToZero(Cell*);


};

#endif // MINESWEEPER_H
