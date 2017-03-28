#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "cell.h"
#include <QtCore>
#include <QtGui>
#include <QGraphicsGridLayout>
#include <QGraphicsWidget>
#include <QVector2D>
#include <iostream>
#include <QMessageBox>
#include <QInputDialog>
#include <QStringList>
#include "minesweeper.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    int width = ui->graphicsView->width();
    int height = ui->graphicsView->height();
    ui->graphicsView->setScene(scene);
    bombs = 65;
    size = 25;

    rows = width/size;
    cols = width/size;
    qInfo() << cols;

    game = new MineSweeper(scene, bombs,rows,cols,size);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_clearButton_clicked()
{
    QStringList list;
    list.append("Easy");
    list.append("Medium");
    list.append("Hard");
    bool accepted = false;

    QString s = QInputDialog::getItem(0,"TEST","Label:",list,0,false,&accepted);

    if(list.indexOf(s) > -1){
        if(list.at(1) == s){
            cols = 24;
            rows = 24;
            bombs = 65;
            size = 25;
        }else if(list.at(0) == s){
            cols = 15;
            rows = 15;
            bombs = 20;
            size = 40;
        }else{
            cols = 50;
            rows = 50;
            bombs = 350;
            size = 12;
        }
    }

    scene->clear();
    delete game;
    game = new MineSweeper(scene,bombs,rows,cols,size);
}
