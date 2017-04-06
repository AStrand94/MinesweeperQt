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
    bool isBomb(); // poor name i chose because "isBomb" was taken :(

    void setNeighbours(Cell **neighbours);
    void reveal();
    void setBomb();

    bool firstPress = true;
    Cell **getNeighbours();
    void setNotBomb();
    bool isNeighbour(Cell*);
    static void setGame(MineSweeper *);
    void drawText();
    void incrementNeighboursBombcount();
    void countNeighbours();
    bool isMarked();
    bool isPressed();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *e);
    //void mouseReleaseEvent(QGraphicsSceneMouseEvent *e);

private:
    int i,size;
    int surroundingBombs = 0;
    bool bomb = false;
    bool pressed = false;
    bool marked = false;
    void revealNeighbours();
    int bombSize;
    QGraphicsTextItem text;
    Cell **neighbours;
    static MineSweeper* game;
    void mark();
    void drawMarkedCell(QPainter *painter);
    void drawBomb(QPainter *painter);
    void drawClickedCell(QPainter *painter);
    void drawUnClickedCell(QPainter *painter);
};

#endif // RECTITEMTEST_H
