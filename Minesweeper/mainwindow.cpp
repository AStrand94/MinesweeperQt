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

    ui->graphicsView->setScene(scene);

    bombs = 60;

    qInfo() << cols;

    createNewGame(25, 25, bombs);
}

void MainWindow::createNewGame(int cols, int rows, int bombs){
    delete game;
    seconds = 0;
    game = new MineSweeper(scene, bombs, rows, cols, this);
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

    QString s = QInputDialog::getItem(0,"TEST","Label:",list,-1,false,&accepted);

    qDebug() << "THE s is: " << s;

    if(s == "") return;

    if(list.indexOf(s) > -1){
        if(list.at(1) == s){
            cols = 24;
            rows = 24;
            bombs = 50;

        }else if(list.at(0) == s){
            cols = 15;
            rows = 15;
            bombs = 20;

        }else{
            cols = 50;
            rows = 50;
            bombs = 500;

        }
    }

    scene->clear();
    createNewGame(cols, rows, bombs);
}

void MainWindow::startTime(){
    timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(updateTimer()));
        timer->start(1000);
}

void MainWindow::updateTimer(){
    displayTime(seconds++);
}

void MainWindow::displayTime(int time){
    qDebug()<<time;
    ui->lcdNumber->display(time);
}
