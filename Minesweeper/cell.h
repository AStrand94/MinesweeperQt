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

    void setNeighbours(Cell **neighbours);
    void reveal();
    void setBomb();

    static bool firstPress;
    bool isBomb();
    bool isNeighbour(Cell*);
    bool isMarked();
    bool isPressed();

    Cell **getNeighbours();
    void setNotBomb();

    static void setGame(MineSweeper *);
    void drawText();
    void incrementNeighboursBombcount();
    void countNeighbours();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *e);

private:
    QGraphicsTextItem text;
    Cell **neighbours;

    int size;
    int surroundingBombs = 0;
    bool bomb = false;
    bool pressed = false;
    bool marked = false;
    bool redBomb = true;
    void revealNeighbours();
    int bombSize;
    static MineSweeper* game;
    void mark();
    void drawMarkedCell(QPainter *painter);
    void drawBomb(QPainter *painter);
    void drawClickedCell(QPainter *painter);
    void drawUnClickedCell(QPainter *painter);
};

#endif // RECTITEMTEST_H
