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
#include <QSlider>
#include <QShortcut>
#include "minesweeper.h"
using namespace std;

bool gamePaused;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    setWindowIcon(QIcon(":/images/mine-01.png"));
    gamePaused = false;
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    qInfo() << cols;
    setGameValuesToMedium();
    createNewGame(cols, rows, bombs);
    ui->pauseButton->setEnabled(false);

    new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_N), this, SLOT(on_clearButton_clicked()));
    new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_P), this, SLOT(on_gamePauseShortcutPressed()));
    new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_L), this, SLOT(on_highscoreButton_clicked()));
}

void MainWindow::setupConnections()
{
    connect(
                game, &MineSweeper::bombMarked,
                this, &MainWindow::decreaseBombDisplayCount
                );
    connect(
                game, &MineSweeper::bombUnMarked,
                this, &MainWindow::increaseBombDisplayCount
                );

    connect(
                game, &MineSweeper::addToTimer,
                this, &MainWindow::addToTimer
                );

    connect(
                game, &MineSweeper::gameOver,
                this, &MainWindow::gameFinished
                );

    connect(
                game, &MineSweeper::gameStarted,
                this, &MainWindow::startTime
                );
}

void MainWindow::createNewGame(int cols, int rows, int bombs){
    delete game;
    if(timer != nullptr)
        delete timer;
    gamePaused = false;
    //game->setImmortalMode(false);
    seconds = 0;
    displayTime(seconds);
    displayBombCount(bombs);
    bombDisplayCount = bombs;
    immortal = false;

    cellSize = 20;
    game = new MineSweeper(scene, bombs, rows, cols,cellSize);

    setupConnections();


    qDebug() << "Resizing scene";
    scene->setSceneRect(0, 0, cellSize*cols, cellSize*rows);
    qDebug() << "Resizing view";
    ui->graphicsView->setFixedSize(cellSize*cols+10, cellSize*rows+10);
    qDebug() << "Resizing window";
    setFixedSize(ui->graphicsView->width()+20, ui->graphicsView->height()+100);

    ui->graphicsView->setEnabled(true);
    timer = new QTimer(this);

    if(ui->actionMute->isChecked()) game->setVolume(0);
    if(ui->actionImmortal->isChecked()) {
        game->setImmortalMode(true);
    }
    else {
        game->setImmortalMode(false);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setButtonText(int buttonSize)
{
    QFont smallxt = ui->clearButton->font();
    smallxt.setPointSize(buttonSize);
    ui->clearButton->setFont(smallxt);
    ui->pauseButton->setFont(smallxt);
    ui->highscoreButton->setFont(smallxt);
}

void MainWindow::setGameValuesToEasy()
{
    cols = 15;
    rows = 15;
    bombs = 20;
    setWindowTitle("Easy");
    setButtonText(8);

}

void MainWindow::setGameValuesToMedium()
{
    cols = 20;
    rows = 20;
    bombs = 50;
    setWindowTitle("Medium");
    setButtonText(13);
}


void MainWindow::setGameValuesToHard()
{
    cols = 30;
    rows = 30;
    bombs = 170;
    setWindowTitle("Hard");
    setButtonText(13);
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

    switch(nbombs){
    case 20:
        d = "Easy";
        break;
    case 70:
        d = "Medium";
        break;
    case 450:
        d = "Hard";
        break;
    default:
        qDebug() << "BOMBS DOES NOT MATCH A SETTING";
        return; //CUSTOM GAME
    }
    if(highscore.newHighscore(d, time)) {
        bool ok;
        QString name = QInputDialog::getText(this, tr("Enter your name"),
                                             tr("Your name:"), QLineEdit::Normal,
                                             QDir::home().dirName(), &ok);

        if (!ok || name.isEmpty()) return;


        highscore.setHighscore(d,name.toStdString(),time);
    }
}

void MainWindow::on_clearButton_clicked()
{
    bool newgame = chooseNewGame();
    if(!newgame) return;
    scene->clear();
    createNewGame(cols, rows, bombs);
}

bool MainWindow::chooseNewGame()
{
    //ui->graphicsView->setEnabled(false);
    QStringList list;
    list.append("Easy");
    list.append("Medium");
    list.append("Hard");
    bool accepted = false;
    QInputDialog *input = new QInputDialog;
    input->setWindowModality(Qt::WindowModal);
    QString s = input->getItem(0,"Difficulty","Choose difficulty:",list,-1,false,&accepted);
    if(s == "") return false;

    if(list.indexOf(s) > -1){
        if(list.at(1) == s){
            setGameValuesToMedium();

        }else if(list.at(0) == s){
            setGameValuesToEasy();

        }else{
            setGameValuesToHard();

        }
    }
    scene->setForegroundBrush(Qt::NoBrush);
    delete input;
    return true;
}

void MainWindow::on_highscoreButton_clicked()
{
    highscore.showHighscore();
}

void MainWindow::decreaseBombDisplayCount(){
    bombDisplayCount--;
    displayBombCount(bombDisplayCount);
    if(bombDisplayCount == 0 && allBombsMarked()){
        gameFinished(true);
    }
}

void MainWindow::increaseBombDisplayCount(){
    bombDisplayCount++;
    displayBombCount(bombDisplayCount);
    if(bombDisplayCount == 0 && allBombsMarked()){
        gameFinished(true);
    }
}

void MainWindow::gameFinished(bool fin){

    timer->stop();
    QString text;
    QMessageBox msg;
    if(fin){
        text = "YOU MADE IT!";
        msg.setIconPixmap(QPixmap(":/images/won.png"));
    }else{
        text = "You failed...";
        msg.setIconPixmap(QPixmap(":/images/lost.png"));
    }
    ui->graphicsView->setEnabled(false);
    ui->pauseButton->setEnabled(false);
    msg.setText(text);
    msg.setWindowModality(Qt::WindowModal);
    msg.exec();

    if(fin) setHighScore();
}

void MainWindow::enablePauseButton(bool boolean)
{
    ui->pauseButton->setEnabled(boolean);
}

void MainWindow::displayBombCount(int bombs){
    ui->lcdNumber_1->display(bombs);
}

void MainWindow::startTime(){
    //timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTimer()));
    timer->start(1000);
    enablePauseButton(true);
}

void MainWindow::updateTimer(){
    displayTime(++seconds);
}

void MainWindow::addToTimer(int seconds)
{
    this->seconds += seconds;
    displayTime(this->seconds);
}

void MainWindow::displayTime(int time){
    ui->lcdNumber->display(time);
}


void MainWindow::on_gamePauseShortcutPressed(){
    if(ui->pauseButton->isEnabled())
        on_pauseButton_clicked();
}

void MainWindow::on_pauseButton_clicked()
{
    //if game is running
    if(!gamePaused) {
        if(timer != NULL) {
            timer->stop();
            scene->setForegroundBrush(QBrush(Qt::darkGray, Qt::SolidPattern));
            ui->graphicsView->setDisabled(true);
            gamePaused = true;
            ui->pauseButton->setText("Resume");
            ui->pauseButton->setStyleSheet(QString("QPushButton {color: green;}"));
            QMessageBox::information(this, "Paused", "Game paused!");
        } else {
            QMessageBox::information(this, "Information", "You need an active game in order to pause!");
        }
    } else {
        ui->pauseButton->setText("Pause");
        ui->pauseButton->setStyleSheet(QString("QPushButton {color: none;}"));
        scene->setForegroundBrush(Qt::NoBrush);
        ui->graphicsView->setDisabled(false);
        timer->start();
        gamePaused = false;
    }
}

void MainWindow::on_actionMute_triggered()
{
    game->setVolume(0);
}

void MainWindow::on_actionImmortal_triggered(){
    QMessageBox msg;
    if(!immortal)ui->actionImmortal->setChecked(true);//new game
    immortal = true;
    if(ui->actionImmortal->isChecked()) {
        msg.setWindowTitle("ON");
        msg.setText("Immortal Mode ON!\n\nBombs will not kill you, but add time..");
        //ui->actionImmortal->setChecked(false);
    }else{
        game->setImmortalMode(false);
        msg.setWindowTitle("OFF");
        msg.setText("Immortal Mode OFF!\n\nBombs will kill you!");
        //ui->actionImmortal->setChecked(true);
    }
    msg.exec();
}

void MainWindow::on_actionGame_Rules_triggered(){
    QMessageBox msg;
    msg.setIconPixmap(QPixmap(":/images/MS_rules_controls_2-01-01.png"));
    msg.setWindowModality(Qt::WindowModal);
    if(timer->isActive()){
        timer->stop();
        scene->setForegroundBrush(QBrush(Qt::darkGray, Qt::SolidPattern));
        if(msg.exec()){
            timer->start();
            scene->setForegroundBrush(Qt::NoBrush);
        }
    }else msg.exec();
}

void MainWindow::on_actionGame_Controls_triggered(){
    QMessageBox msg;
    msg.setIconPixmap(QPixmap(":/images/MS_rules_controls_2-03-01.png"));
    msg.setWindowModality(Qt::WindowModal);
    if(timer->isActive()){
        timer->stop();
        scene->setForegroundBrush(QBrush(Qt::darkGray, Qt::SolidPattern));
        if(msg.exec()){
            timer->start();
            scene->setForegroundBrush(Qt::NoBrush);
        }
    }else msg.exec();
}

//actionGame_Rules_and_Controls

