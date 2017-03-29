#include <iostream>
#include "minesweeper.h"
#include "cell.h"
#include <ctime>

MineSweeper::MineSweeper(QGraphicsScene *scene,int bombs, int rows, int columns)
{
    //if(bombs > rows*columns)   --->>> THROW EXCEPTION??
    if(bombs > rows*columns) bombs = rows*columns -1;
    this->scene = scene;
    this->bombCount = bombs;
    //allBombs = new Cell*[bombCount];
    //allBombs = 0;
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
    deleteGrid();

    scene = NULL;
}

void MineSweeper::firstIsPressed(Cell *cell)
{
    qDebug() << "setting bombs everywere, but not on cell or cells neighbours";
    setBombsAround(cell);


    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            grid[i][j]->firstPress = false;
        }
    }
}

void MineSweeper::deleteGrid(){

    //Because scene.clear() is called, it is not necessary to clear
    //each item item in the ***grid, because that would couse a double delete,
    //and make the program crash

    for(int i = 0; i < rows; i++) delete[] grid[i];

    delete[] grid;
    if(allBombs != nullptr){
        delete[] allBombs;
        allBombs = NULL;
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

            grid[i][j]->setGame(this);

            scene->addItem(grid[i][j]);
        }
    }
    //grid[0][0]->setParent(this);
}

void MineSweeper::setBombsAround(Cell* cell)
{
    //bombCount++;

    allBombs = new Cell*[bombCount];

    int bombIndex = 0;

    srand((unsigned int)time(0));


    qDebug() << "Entering loop that could take forever";
    while(bombIndex < bombCount){

        int x = rand() % rows;
        int y = rand() % cols;

        if(!grid[x][y]->isNeighbour(cell) && grid[x][y] != cell){
            grid[x][y]->setBomb();
            qDebug() << "Incrementing: " << x << ", " << y;
            //grid[x][y]->incrementNeighboursBombcount();
            allBombs[bombIndex++] = grid[x][y];
        }
    }

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            grid[i][j]->countNeighbours();
        }
    }

    qDebug() << "Exiting loop that could take forever :D";
}

void MineSweeper::revealeAllBombs(){
    if(!isBombsRevealed){
        isBombsRevealed = true;
        for(int i = 0; i < bombCount; i++){
            allBombs[i]->reveal();
        }
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




