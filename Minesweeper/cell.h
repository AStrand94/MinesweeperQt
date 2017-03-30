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
    bool isItBomb(); // poor name i chose because "isBomb" was taken :(

    void setNeighbours(Cell **neighbours);
    void reveal();
    void setBomb();

    bool firstPress = true;
    Cell **getNeighbours();
    void setNotBomb();
    bool isNeighbour(Cell*);
    void setGame(MineSweeper *);
    void drawText();
    void incrementNeighboursBombcount();
    void countNeighbours();
    bool isMarked();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *e);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *e);

private:
    int i,size;
    int surroundingBombs = 0;
    bool isBomb = false;
    bool isPressed = false;
    void revealNeighbours();
    int bombSize;
    bool marked = false;
    QGraphicsTextItem text;
    MineSweeper* game;
    Cell **neighbours;

    void mark();
};

#endif // RECTITEMTEST_H
