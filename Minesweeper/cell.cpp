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
    QRectF rec = boundingRect();
    QBrush brush;
    if(marked){
        brush = QBrush(Qt::yellow);
    }else if(isPressed){
        if(isBomb){
            brush = QBrush(Qt::darkRed);
        }else{
            brush = QBrush(Qt::white);
        }
    }else{
        brush = QBrush(Qt::darkGray);
    }

    painter->fillRect(rec,brush);

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

bool Cell::isItBomb(){
    return isBomb;
}

void Cell::setNeighbours(Cell **informs)
{
    this->neighbours = informs;
}

void Cell::revealNeighbours(){
        for(int i = 0; i < 8; i++){
            if(neighbours[i] != NULL)
                if( !neighbours[i]->isPressed)
                    neighbours[i]->reveal();
        }

}

void Cell::countNeighbours()
{
    for(int i = 0; i < 8; i++){
        if(neighbours[i] != 0 && neighbours[i]->isBomb)
            surroundingBombs++;
    }
}

void Cell::incrementNeighboursBombcount(){
    for(int i = 0; i < 8; i++){
        if(neighbours[i] != NULL){
            neighbours[i]->surroundingBombs++;
        }
    }
}



void Cell::drawText(){
    double scaleSize = 1.0;


    if(isBomb){

        text.setPlainText("B");
        text.setScale(scaleSize);
        text.setTextWidth(size);
        text.setPos(0,0);
        text.setParentItem(this);

        text.show();
    }else if(surroundingBombs > 0){

        text.setPlainText(QString::number(surroundingBombs));
        text.setScale(scaleSize);
        text.setPos(0,0);
        text.setParentItem(this);
        text.show();
    }
    isPressed = true;
    update();
}

void Cell::setBomb()
{
    isBomb = true;
}

Cell **Cell::getNeighbours()
{
    return neighbours;
}

void Cell::setNotBomb()
{
    isBomb = false;
}

bool Cell::isNeighbour(Cell *cell)
{
    for(int i = 0; i < 8; i++) if(neighbours[i] == cell) return true;
    return false;
}

void Cell::mark()
{
    if(!isPressed){
        marked = !marked;
        game->onCellMarked(marked);
        update();
    }
}

void Cell::reveal()
{
    if(!isPressed && !marked){
        isPressed = true;
        if(isItBomb()){
            game->revealeAllBombs();
        }else if(surroundingBombs == 0) revealNeighbours();
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
    }
    QGraphicsItem::mousePressEvent(e);

}

void Cell::mouseReleaseEvent(QGraphicsSceneMouseEvent *e)
{
    QGraphicsItem::mouseReleaseEvent(e); //stopper visst utførelse av resten av funksjonen
}
