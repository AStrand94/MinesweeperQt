#include "cell.h"
#include <iostream>
#include <QGraphicsSceneMouseEvent>
#include <QMessageBox>
#include <minesweeper.h>


Cell::Cell(int size,MineSweeper* game){
    this->game = game;
    this->size = size;
}

Cell::~Cell()
{
    delete[] informs;
    //delete text;
    //text = NULL;
    //delete[] allBombs;
}

void Cell::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();
    QBrush brush;
    if(marked){
        brush = QBrush(Qt::yellow);
    }else if(isPressed){
        if(bomb){
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

QSizeF Cell::sizeHint(Qt::SizeHint which, const QSizeF &constraint) const
{
    return boundingRect().size();
}

void Cell::setGeometry(const QRectF &r)
{
    prepareGeometryChange();
    QGraphicsLayoutItem::setGeometry(r);
    setPos(r.topLeft());
}

bool Cell::isBomb(){
    return bomb;
}

void Cell::setBombs(int b)
{
    bombs = b;
}

void Cell::setInforms(Cell **informs)
{
    this->informs = informs;
}

void Cell::informNext(){
    isPressed = true;
    reveal();
    update();
    if(bombs == 0){
        for(int i = 0; i < 8; i++){
            if(informs[i] != NULL)
                if( !informs[i]->isPressed)
                    informs[i]->informNext();
        }
    }
}

void Cell::revealAllBombs()
{
    for(int i = 0; i < bombSize; i++) allBombs[i]->reveal();
}

void Cell::reveal(){
    double scaleSize;
    if(size == 25) scaleSize = 1.0;
    else if(size == 40) scaleSize = 1.3;
    else scaleSize = 0.5;


    if(bomb){

        text.setPlainText("B");
        text.setScale(scaleSize);
        text.setPos(0,0);
        text.setParentItem(this);

        text.show();
    }else if(bombs > 0){

        text.setPlainText(QString::number(bombs));
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
    bomb = true;
}

int Cell::getBombs()
{
    return bombs;
}

void Cell::setBombsReference(Cell **bombref, int size)
{
    this->allBombs = bombref;
    this->bombSize = size;
}

Cell **Cell::getInforms()
{
    return informs;
}

void Cell::setNotBomb()
{
    bomb = false;
}

bool Cell::isNeighbour(Cell *cell)
{
    for(int i = 0; i < 8; i++) if(informs[i] == cell) return true;
    return false;
}

void Cell::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
    bool right = e->button() == Qt::RightButton;
    if(firstPress && !right){
        game->firstIsPressed(this);
    }

    if(right) {
        if(!isPressed){
            marked = !marked;
            update();
        }
    }else{
        if(!isPressed && !marked){
            if(isBomb()){
                revealAllBombs();
            }else{

                if(bombs == 0) informNext();
                isPressed = true;
                reveal();
            }
        }
    }
    QGraphicsItem::mousePressEvent(e);

}

void Cell::mouseReleaseEvent(QGraphicsSceneMouseEvent *e)
{
    test = 0;
    QGraphicsItem::mouseReleaseEvent(e); //stopper visst utførelse av resten av funksjonen
}
