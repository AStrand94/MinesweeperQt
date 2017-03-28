#include <iostream>
#include "minesweeper.h"
#include "cell.h"

MineSweeper::MineSweeper(QGraphicsScene *scene,int bombs, int rows, int columns, int cellsize)
{
    //if(bombs > rows*columns)   --->>> THROW EXCEPTION
    if(bombs > rows*columns) bombs = rows*columns -1;
    this->scene = scene;
    this->bombs = bombs;
    this->rows = rows;
    this->cols = columns;
    this->size = cellsize;
    createGrid();
    setBombs(bombs);
    setNeighbourBombs();
    setInform();
}

MineSweeper::~MineSweeper()
{
    scene = NULL;

}

void MineSweeper::firstIsPressed(Cell *cell)
{
    if(cell->isBomb()  || cell->getBombs() > 0){
        setCellBombsToZero(cell);
    }

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

void MineSweeper::setCellBombsToZero(Cell *cell)
{

    Cell **informs = cell->getInforms();
    if(cell->isBomb()){
        cell->setNotBomb();
        while(true){
            int x = rand()%rows, y = rand()%cols;
            if(!cell->isNeighbour(grid[x][y])){
                grid[x][y]->setBomb();
                break;
            }
        }
    }

    for(int i = 0; i < 8; i++){
        if(informs[i]->isBomb()){
            informs[i]->setNotBomb();
            while(true){
                int x = rand()%rows, y = rand()%cols;
                if(!cell->isNeighbour(grid[x][y])){
                    grid[x][y]->setBomb();
                    break;
                }
            }
        }
    }

    setNeighbourBombs();

}

void MineSweeper::createGrid()
{


    grid = new Cell**[rows];

    for(int i = 0; i < rows; i++){
        grid[i] = new Cell*[cols];
        for(int j = 0; j < cols; j++){
            grid[i][j] = new Cell(size,this);
            grid[i][j]->setPos(i*size,j*size);
            scene->addItem(grid[i][j]);
        }
    }
}

void MineSweeper::setBombs(int x)
{
    allBombs = new Cell*[x];
    int bombIndex = 0;
    int temp = x;
    srand((unsigned int)time(0));

    while(temp != 0){
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(rand() % 30 == 0 && !grid[i][j]->isBomb()){
                    grid[i][j]->setBomb();
                    allBombs[bombIndex++] = grid[i][j];
                    grid[i][j]->setBombsReference(allBombs,x);
                    temp--;
                    if(temp == 0) break;
                }
             }
            if(temp == 0) break;
        }
    }
}

void MineSweeper::setNeighbourBombs()
{
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            grid[i][j]->setBombs(getBombs(i,j));
        }
    }
}

int MineSweeper::getBombs(int x, int y)
{
    int bombs=0;

    if(x != 0){
        if(grid[x-1][y]->isBomb()){
            bombs++;
        }
    }

    if(x!=0 && y!=0){
        if(grid[x-1][y-1]->isBomb()){
            bombs++;
        }
    }

    if(y != 0){
        if(grid[x][y-1]->isBomb()){
            bombs++;
        }
    }

    if(x != (rows-1)){
        if(grid[x+1][y]->isBomb()){
            bombs++;
        }
    }

    if(y != (cols-1)){
        if(grid[x][y+1]->isBomb()){
            bombs++;
        }
    }

    if(x != (rows-1) && y != (cols-1)){
        if(grid[x+1][y+1]->isBomb()){
            bombs++;
        }
    }

    if(x != 0 && y != (cols-1)){
        if(grid[x-1][y+1]->isBomb()){
            bombs++;
        }
    }

    if(x != (rows-1) && y != 0){
        if(grid[x+1][y-1]->isBomb()){
            bombs++;
        }
    }

    return bombs;
}

void MineSweeper::setInform()
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

            grid[i][j]->setInforms(inf);

        }
    }
}




