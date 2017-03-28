#include <iostream>
#include "minesweeper.h"
#include "cell.h"

MineSweeper::MineSweeper(QGraphicsScene *scene,int bombs, int rows, int columns)
{
    //if(bombs > rows*columns)   --->>> THROW EXCEPTION
    if(bombs > rows*columns) bombs = rows*columns -1;
    this->scene = scene;
    this->bombCount = bombs;
    this->rows = rows;
    this->cols = columns;
    //this->size = cellsize;
    createBlankGrid();
    setNeighbours();
    qDebug() << "Game created";
    qDebug() << "rows " << rows;
    qDebug() << "cols " << columns;
    qDebug() << "bombs" << bombs;


}

MineSweeper::~MineSweeper()
{
    scene = NULL;
}

void MineSweeper::firstIsPressed(Cell *cell)
{
    qDebug() << "setting surroudning bombs";
    setBombsAround(cell);

    qDebug() << "Test";
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            grid[i][j]->firstPress = false;
        }
    }
}

void MineSweeper::deleteGrid(){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            delete grid[i][j];
        }
        delete[] grid[i];
    }
}


void MineSweeper::createBlankGrid()
{
    grid = new Cell**[rows];

    for(int i = 0; i < rows; i++){
        grid[i] = new Cell*[cols];
        for(int j = 0; j < cols; j++){
            grid[i][j] = new Cell(size);
            grid[i][j]->setPos(i*size,j*size);

            grid[i][j]->setParent(this);

            scene->addItem(grid[i][j]);
        }
    }
    //grid[0][0]->setParent(this);
}

void MineSweeper::setBombsAround(Cell* cell)
{

    qDebug() << "before";
    bombCount++;
    qDebug() << "After";

    allBombs = new Cell*[bombCount];

    int bombIndex = 0;

    srand((unsigned int)time(0));


    qDebug() << "Entering while loop";
    while(bombIndex < bombCount){

        int x = rand() % rows;
        int y = rand() % cols;

        if(!grid[x][y]->isNeighbour(cell) && grid[x][y] != cell){
            grid[x][y]->setBomb();
            grid[x][y]->incrementNeighboursBombcount();
           allBombs[bombIndex++] = grid[x][y];
        }
    }
}

void MineSweeper::revealeAllBombs(){
    for(int i = 0; i < bombCount; i++){
        allBombs[i]->reveal();
    }
}

void MineSweeper::setNeighbours()
{
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            Cell** inf = new Cell*[8];

            if(i != 0)
                inf[0] = grid[i-1][j];
            else
                inf[0] = NULL;

            if(j != 0)
                inf[1] = grid[i][j-1];
            else
                inf[1] = NULL;

            if(i != rows-1)
                inf[2] = grid[i+1][j];
            else
                inf[2] = NULL;

            if(j != cols-1)
                inf[3] = grid[i][j+1];
            else
                inf[3] = NULL;

            if(i != 0 && j != 0)
                inf[4] = grid[i-1][j-1];
            else
                inf[4] = NULL;

            if(i != 0 && j !=cols-1)
                inf[5] = grid[i-1][j+1];
            else
                inf[5] = NULL;

            if(i != rows-1 && j != 0)
                inf[6] = grid[i+1][j-1];
            else
                inf[6] = NULL;

            if(i != rows-1 && j != cols-1)
                inf[7] = grid[i+1][j+1];
            else
                inf[7] = NULL;

            grid[i][j]->setNeighbours(inf);

        }
    }
}




