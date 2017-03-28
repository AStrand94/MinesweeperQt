#ifndef CELL_H
#define CELL_H
#include <QtGui>
#include <QtCore>
#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QRectF>
#include <QGraphicsLayoutItem>
#include <QPainter>

using namespace std;

class MineSweeper;

class Cell : public QGraphicsItem, public QGraphicsLayoutItem
{
public:
    Cell(int size);
    ~Cell();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem * option, QWidget *widget);
    QRectF boundingRect() const;
    QSizeF sizeHint(Qt::SizeHint which, const QSizeF &constraint) const;
   // void setGeometry(const QRectF &r);
    bool isItBomb();
    void setBombs(int b);
    void setNeighbours(Cell **neighbours);
    void reveal();
    void setBomb();
    int getBombs();
    void setBombsReference(Cell**,int);
    bool firstPress = true;
    Cell **getNeighbours();
    void setNotBomb();
    bool isNeighbour(Cell*);
    void setParent(MineSweeper *);
    void drawText();
    void incrementNeighboursBombcount();


protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *e);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *e);

private:
    int i,size;
    int test = 0;
    int surroundingBombs = 0;
    bool isBomb = false;
    bool isPressed = false;
    //QGraphicsTextItem *text;
    Cell **neighbours;
    void revealNeighbours();
    Cell **allBombs;
    int bombSize;

    QGraphicsTextItem text;
    bool marked = false;
    MineSweeper* game;

    void mark();
};

#endif // RECTITEMTEST_H
