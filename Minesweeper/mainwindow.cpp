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

    qInfo() << cols;


    setGameValuesToMedium();

    createNewGame(cols, rows, bombs);
}

void MainWindow::createNewGame(int cols, int rows, int bombs){
    delete game;
    delete timer;
    seconds = 0;
    displayTime(seconds);
    displayBombCount(bombs);
    bombDisplayCount = bombs;
    game = new MineSweeper(scene, bombs, rows, cols, this);

    //must be same as in minesweeper.h, TODO link them
    int cellSize = 20;

    qDebug() << "Resizing scene";
    scene->setSceneRect(0, 0, cellSize*cols, cellSize*rows);
    qDebug() << "Resizing view";
    ui->graphicsView->setFixedSize(cellSize*cols+10, cellSize*rows+10);
    qDebug() << "Resizing window";
    setFixedSize(ui->graphicsView->width()+20, ui->graphicsView->height()+100);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setGameValuesToMedium()
{
    cols = 24;
    rows = 24;
    bombs = 70;
}

void MainWindow::setGameValuesToEasy()
{
    cols = 15;
    rows = 15;
    bombs = 20;
}

void MainWindow::setGameValuesToHard()
{
    cols = 40;
    rows = 40;
    bombs = 500;
}

bool MainWindow::allBombsMarked()
{
    return game->allBombsMarked();
}

void MainWindow::setHighScore()
{
    string d;
    int time = seconds;
    int nbombs = game->getBombs();
    qDebug() << nbombs << "HEIHEIHEIHEIHIE";

    switch(nbombs){
    case 20:
        d = "Easy";
        break;
    case 70:
        d = "Medium";
        break;
    case 500:
        d = "Hard";
        break;
    default:
        qDebug() << "BOMBS DOES NOT MATCH A SETTING";
        return; //CUSTOM GAME
    }

    if(highscore.newHighscore(d, time)) {

        bool ok;
        QString name = QInputDialog::getText(this, tr("QInputDialog::getText()"),
                                             tr("Your name:"), QLineEdit::Normal,
                                             QDir::home().dirName(), &ok);
        if (!ok || name.isEmpty()) return;

        highscore.setHighscore(d,name.toStdString(),time);
    }
}

void MainWindow::on_clearButton_clicked()
{
    QStringList list;
    list.append("Easy");
    list.append("Medium");
    list.append("Hard");
    bool accepted = false;

    QString s = QInputDialog::getItem(0,"TEST","Label:",list,-1,false,&accepted);
    Difficulty d = HARD;

    qDebug() << "THE s is: " << s;
    qDebug() << "THE difficulty is: " << d;

    if(s == "") return;

    if(list.indexOf(s) > -1){
        if(list.at(1) == s){
            setGameValuesToMedium();

        }else if(list.at(0) == s){
            setGameValuesToEasy();

        }else{
            setGameValuesToHard();

        }
    }

    scene->clear();
    createNewGame(cols, rows, bombs);
}

void MainWindow::on_highscoreButton_clicked()
{
    highscore.showHighscore();
}

void MainWindow::decreaseBombDisplayCount(){
    bombDisplayCount--;
    displayBombCount(bombDisplayCount);
    if(bombDisplayCount == 0 && allBombsMarked()){
        QMessageBox msg;
        string s = to_string(seconds);
        msg.setText("You made it!!!!!");
        msg.exec();
        setHighScore();
    }
}
void MainWindow::increaseBombDisplayCount(){
    bombDisplayCount++;
    displayBombCount(bombDisplayCount);
    if(bombDisplayCount == 0 && allBombsMarked()){
        QMessageBox msg;
        string s = to_string(seconds);
        msg.setText("You made it!!!!!");
        msg.exec();
        setHighScore();
    }
}

void MainWindow::displayBombCount(int bombs){
    ui->lcdNumber_1->display(bombs);
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
    ui->lcdNumber->display(time);
}
