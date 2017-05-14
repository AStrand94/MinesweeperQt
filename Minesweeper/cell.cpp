#include "cell.h"
#include <iostream>
#include <QGraphicsSceneMouseEvent>
#include <QMessageBox>
#include <minesweeper.h>


Cell::Cell(int size){
    this->size = size;
}

Cell::~Cell()
{
    //Delete all arrays. The cells appointed by the arrays should already be cleared
    //by the scene.clear() function.

    delete[] neighbours;
}

void Cell::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(marked){
        drawMarkedCell(painter);
    }else if(pressed){
        if(bomb){
            //if(redBomb)drawTheBomb(painter); //makes bombCells blink when first bomb is pressed when !immortalMode
            drawBomb(painter);
        }else{
            drawClickedCell(painter);
        }
    }else{
        drawUnClickedCell(painter);
    }
}


MineSweeper *Cell::game;
bool Cell::firstPress;

void Cell::drawMarkedCell(QPainter* painter){
    QBrush brush = Qt::transparent;
    painter->fillRect(boundingRect(), brush);
    QImage wrn(":/images/flag-01.png", 0);
    painter->drawImage(boundingRect(), wrn);
    painter->drawRect(boundingRect());
}

void Cell::drawBomb(QPainter* painter){
    QBrush brush = Qt::transparent;
    if(redBomb)brush = Qt::red;
    painter->fillRect(boundingRect(), brush);
    QImage bmb(":/images/mine-01.png", 0);
    painter->drawImage(boundingRect(), bmb);
    painter->drawRect(boundingRect());
    redBomb = false;
}

void Cell::drawClickedCell(QPainter* painter){
    QBrush brush = Qt::white;

    painter->fillRect(boundingRect(), brush);
    painter->drawRect(boundingRect());
}

void Cell::drawUnClickedCell(QPainter* painter){
    QLinearGradient gradient(boundingRect().topLeft(), boundingRect().bottomRight());
    gradient.setColorAt(0,Qt::lightGray);
    gradient.setColorAt(1, Qt::darkGray);
    painter->fillRect(boundingRect(), gradient);
    painter->drawRect(boundingRect());
}


QRectF Cell::boundingRect() const{
    return QRectF(0,0,size,size);
}

void Cell::setGame(MineSweeper* p){
    game = p;
}

QSizeF Cell::sizeHint(Qt::SizeHint which, const QSizeF &constraint) const
{
    return boundingRect().size();
}

/*void Cell::setGeometry(const QRectF &r)
{
    prepareGeometryChange();
    QGraphicsLayoutItem::setGeometry(r);
    setPos(r.topLeft());
}*/

bool Cell::isBomb(){
    return bomb;
}

void Cell::setNeighbours(Cell **informs)
{
    this->neighbours = informs;
}

void Cell::revealNeighbours(){
    for(int i = 0; i < 8; i++){
        if(neighbours[i] != NULL)
            if( !neighbours[i]->pressed)
                neighbours[i]->reveal();
    }

}

void Cell::countNeighbours()
{
    for(int i = 0; i < 8; i++){
        if(neighbours[i] != 0 && neighbours[i]->bomb)
            surroundingBombs++;
    }
}

bool Cell::isMarked()
{
    return marked;
}

bool Cell::isPressed()
{
    return pressed;
}

void Cell::incrementNeighboursBombcount(){
    for(int i = 0; i < 8; i++){
        if(neighbours[i] != NULL){
            neighbours[i]->surroundingBombs++;
        }
    }
}




void Cell::setBomb()
{
    bomb = true;
}

Cell **Cell::getNeighbours()
{
    return neighbours;
}

void Cell::drawText(){

    double scaleSize = size/20; // apparently scalesize 1 fits a 20x20 square perfectly
    switch (surroundingBombs) {
    case 1: text.setDefaultTextColor(Qt::blue);
        break;
    case 2: text.setDefaultTextColor(Qt::darkGreen);
        break;
    case 3: text.setDefaultTextColor(Qt::red);
        break;
    case 4: text.setDefaultTextColor(Qt::darkBlue);
        break;
    case 5: text.setDefaultTextColor(Qt::darkRed);
        break;
    case 6: text.setDefaultTextColor(Qt::darkCyan);
        break;
    case 7: text.setDefaultTextColor(Qt::black);
        break;
    default:text.setDefaultTextColor(Qt::lightGray);
        break;
    }
    text.setPlainText(bomb?"":surroundingBombs > 0 ? QString::number(surroundingBombs) : "");
    text.setFont(QFont("arial",15));
    text.setScale(scaleSize);
    text.setPos(1,-2);
    text.setParentItem(this);
    text.show();

}

void Cell::setNotBomb()
{
    bomb = false;
}

bool Cell::isNeighbour(Cell *cell)
{
    for(int i = 0; i < 8; i++) if(neighbours[i] == cell) return true;
    return false;
}

void Cell::mark()
{
    if(!pressed){
        marked = !marked;
        game->onCellMarked(marked);
        update();
    }
}

void Cell::reveal()
{
    if(!pressed && !marked){
        pressed = true;
        if(isBomb()){
            game->playSound();
            if(game->getImmortalMode() == false) {
                game->revealeAllBombs();
            } else {
                redBomb = false;
                game->updateTimer(10);
                game->decreaseBombDisplayCount();
            }
        }else if(surroundingBombs == 0)
            revealNeighbours();

        drawText();
    }
    update();
}

void Cell::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
    bool right = e->button() == Qt::RightButton;
    if(firstPress && !right){
        qDebug() << "First klick :D";
        game->firstIsPressed(this);
    }

    if(right) {
        mark();
    }else if(!marked){
        reveal();
        game->checkIfWon();
    }

    QGraphicsItem::mousePressEvent(e);
}
