#include <iostream>
#include "minesweeper.h"
#include "cell.h"
#include <ctime>
#include <QMediaPlayer>

MineSweeper::MineSweeper(QGraphicsScene *scene,int bombs, int rows, int columns,int cellSize)
{
    if(bombs > rows*columns) bombs = rows*columns -1;
    this->scene = scene;
    this->bombCount = bombs;
    allBombs = new Cell*[bombCount];
    this->rows = rows;
    this->cols = columns;
    this->size = cellSize;
    createBlankGrid();
    setNeighbours();
    Cell::firstPress = true;
    qDebug() << "Game created";
    qDebug() << "rows " << rows;
    qDebug() << "cols " << columns;
    qDebug() << "bombs" << bombs;
    player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/sounds/bomb.mp3"));
    player->setVolume(15);
    immortalMode = false;
}

MineSweeper::~MineSweeper()
{
    deleteGrid();
    delete player;
    scene = NULL;
}

void MineSweeper::firstIsPressed(Cell *cell)
{
    qDebug() << "setting bombs everywere, but not on cell or cells neighbours";
    setBombsAround(cell);

    emit gameStarted();

    Cell::firstPress = false;
}

void MineSweeper::onCellMarked(bool marked){
    if(!marked)
        emit bombUnMarked();
    else
        emit bombMarked();
}

bool MineSweeper::allBombsMarked()
{
    if(!bombsAreSet) return false;
    int currentMarkCount = 0;
    qDebug() << bombCount;

    for(int i = 0; i < bombCount; i++){
        qDebug() << "HALLO" << i;
        if(allBombs[i]->isMarked()){
            currentMarkCount++;
        }
    }
    return currentMarkCount == bombCount;
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

    Cell::setGame(this);

    for(int i = 0; i < rows; i++){
        grid[i] = new Cell*[cols];
        for(int j = 0; j < cols; j++){
            grid[i][j] = new Cell(size);
            grid[i][j]->setPos(i*size,j*size);
            scene->addItem(grid[i][j]);
        }
    }
}

void MineSweeper::setBombsAround(Cell* cell)
{
    int bombIndex = 0;

    srand((unsigned int)time(0));

    qDebug() << "Entering loop that could take forever";
    while(bombIndex < bombCount){

        int x = rand() % rows;
        int y = rand() % cols;

        if(!grid[x][y]->isNeighbour(cell) && grid[x][y] != cell && !grid[x][y]->isBomb()){
            grid[x][y]->setBomb();
            qDebug() << "Incrementing: " << x << ", " << y;
            allBombs[bombIndex++] = grid[x][y];
        }
    }

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            grid[i][j]->countNeighbours();
        }
    }

    bombsAreSet = true;
    qDebug() << "Exiting loop that could take forever :D";
}

int MineSweeper::getBombs()
{
    return bombCount;
}

void MineSweeper::checkIfWon()
{
    qDebug() << "Did you win?";
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(!grid[i][j]->isPressed() && !grid[i][j]->isBomb()){
                qDebug() << "No :(";
                return;
            }
        }
    }
    qDebug() << "Yes :)";
    emit gameOver(true);
}

void MineSweeper::playSound()
{
    if(immortalMode && player->state() == 1) {
        player->stop();
    }
    player->play();
}

void MineSweeper::setVolume(int volume)
{
    player->setVolume(volume);
}

void MineSweeper::setImmortalMode(bool modeOn)
{
    immortalMode = modeOn;
}

bool MineSweeper::getImmortalMode()
{
    return this->immortalMode;
}

void MineSweeper::updateTimer(int seconds)
{
    emit addToTimer(seconds);
}

void MineSweeper::decreaseBombDisplayCount()
{
    emit bombMarked();
}

void MineSweeper::revealeAllBombs(){
    if(!isBombsRevealed){
        isBombsRevealed = true;
        for(int i = 0; i < bombCount; i++){
            allBombs[i]->reveal();
        }

        emit gameOver(false);
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
