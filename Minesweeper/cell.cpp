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
            drawBomb(painter);
        }else{
            drawClickedCell(painter);
        }
    }else{
        drawUnClickedCell(painter);
    }
}

void Cell::drawMarkedCell(QPainter* painter){
    QBrush brush = Qt::yellow;
    painter->fillRect(boundingRect(), brush);

    painter->drawRect(boundingRect());
}

void Cell::drawBomb(QPainter* painter){
    QBrush brush = Qt::red;
    painter->fillRect(boundingRect(), brush);

    painter->drawRect(boundingRect());



}

void Cell::drawClickedCell(QPainter* painter){
    QBrush brush = Qt::white;
    painter->fillRect(boundingRect(), brush);

    painter->drawRect(boundingRect());
}

void Cell::drawUnClickedCell(QPainter* painter){
    QBrush brush = Qt::gray;
    painter->fillRect(boundingRect(), brush);

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
    double scaleSize = 1.0;

    text.setPlainText(bomb?"B":surroundingBombs > 0 ? QString::number(surroundingBombs) : "");
    text.setScale(scaleSize);
    text.setPos(0,0);
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
            game->revealeAllBombs();
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

/*void Cell::mouseReleaseEvent(QGraphicsSceneMouseEvent *e)
{
    QGraphicsItem::mouseReleaseEvent(e); //stopper visst utførelse av resten av funksjonen
}*/
