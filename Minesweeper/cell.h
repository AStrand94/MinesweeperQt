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
    Cell(int size,MineSweeper*);
    ~Cell();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem * option, QWidget *widget);
    QRectF boundingRect() const;
    QSizeF sizeHint(Qt::SizeHint which, const QSizeF &constraint) const;
    void setGeometry(const QRectF &r);
    bool isBomb();
    void setBombs(int b);
    void setInforms(Cell **informs);
    void reveal();
    void setBomb();
    int getBombs();
    void setBombsReference(Cell**,int);
    bool firstPress = true;
    Cell **getInforms();
    void setNotBomb();
    bool isNeighbour(Cell*);


protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *e);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *e);

private:
    int i,size;
    int test = 0;
    int bombs = 0;
    bool bomb = false;
    bool isPressed = false;
    //QGraphicsTextItem *text;
    Cell **informs;
    void informNext();
    Cell **allBombs;
    int bombSize;
    void revealAllBombs();
    QGraphicsTextItem text;
    bool marked = false;
    MineSweeper *game;

};

#endif // RECTITEMTEST_H
