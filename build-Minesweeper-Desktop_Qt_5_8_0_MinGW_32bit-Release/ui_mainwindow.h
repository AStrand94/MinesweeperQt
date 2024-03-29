/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionMute;
    QAction *actionImmortal;
    QAction *actionHow_to_play;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsView;
    QHBoxLayout *horizontalLayout;
    QLCDNumber *lcdNumber;
    QPushButton *clearButton;
    QPushButton *pauseButton;
    QPushButton *highscoreButton;
    QLCDNumber *lcdNumber_1;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuSound;
    QMenu *menuHelp;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(600, 723);
        MainWindow->setMinimumSize(QSize(600, 700));
        MainWindow->setMaximumSize(QSize(624, 800));
        MainWindow->setStyleSheet(QLatin1String("QMainWindow {\n"
"    background: #333333;\n"
"    width: 10px; /* when vertical */\n"
"    height: 10px; /* when horizontal */\n"
"}"));
        actionMute = new QAction(MainWindow);
        actionMute->setObjectName(QStringLiteral("actionMute"));
        actionMute->setCheckable(true);
        actionImmortal = new QAction(MainWindow);
        actionImmortal->setObjectName(QStringLiteral("actionImmortal"));
        actionImmortal->setCheckable(true);
        actionHow_to_play = new QAction(MainWindow);
        actionHow_to_play->setObjectName(QStringLiteral("actionHow_to_play"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setMinimumSize(QSize(1762, 882));
        graphicsView->setMaximumSize(QSize(600, 600));
        graphicsView->setStyleSheet(QLatin1String("QGraphicsView{\n"
"	background-color: white;\n"
"}"));

        verticalLayout->addWidget(graphicsView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setStyleSheet(QLatin1String("QLCDNumber{\n"
"	color: white;\n"
"    background-color: black;\n"
"	border: 1px solid red;\n"
"}"));

        horizontalLayout->addWidget(lcdNumber);

        clearButton = new QPushButton(centralWidget);
        clearButton->setObjectName(QStringLiteral("clearButton"));
        clearButton->setEnabled(true);
        clearButton->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(clearButton);

        pauseButton = new QPushButton(centralWidget);
        pauseButton->setObjectName(QStringLiteral("pauseButton"));

        horizontalLayout->addWidget(pauseButton);

        highscoreButton = new QPushButton(centralWidget);
        highscoreButton->setObjectName(QStringLiteral("highscoreButton"));

        horizontalLayout->addWidget(highscoreButton);

        lcdNumber_1 = new QLCDNumber(centralWidget);
        lcdNumber_1->setObjectName(QStringLiteral("lcdNumber_1"));
        lcdNumber_1->setStyleSheet(QLatin1String("QLCDNumber{\n"
"    color: white;    \n"
"    background-color: black;\n"
"	border: 1px solid red;\n"
"}"));

        horizontalLayout->addWidget(lcdNumber_1);


        verticalLayout->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 16));
        menuBar->setStyleSheet(QLatin1String(" QMenuBar {\n"
"     background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"                                       stop:0 lightgray, stop:1 darkgray);\n"
" }\n"
"\n"
" QMenuBar::item {\n"
"     spacing: 3px; /* spacing between menu bar items */\n"
"     padding: 1px 4px;\n"
"     background: transparent;\n"
"     border-radius: 4px;\n"
" }\n"
"\n"
" QMenuBar::item:selected { /* when selected using mouse or keyboard */\n"
"     background: #a8a8a8;\n"
" }\n"
"\n"
" QMenuBar::item:pressed {\n"
"     background: #888888;\n"
" }"));
        menuSound = new QMenu(menuBar);
        menuSound->setObjectName(QStringLiteral("menuSound"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuSound->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuSound->addAction(actionImmortal);
        menuSound->addAction(actionMute);
        menuHelp->addAction(actionHow_to_play);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionMute->setText(QApplication::translate("MainWindow", "Mute", Q_NULLPTR));
        actionImmortal->setText(QApplication::translate("MainWindow", "Immortal Mode", Q_NULLPTR));
        actionHow_to_play->setText(QApplication::translate("MainWindow", "How to play", Q_NULLPTR));
        clearButton->setText(QApplication::translate("MainWindow", "New Game", Q_NULLPTR));
        pauseButton->setText(QApplication::translate("MainWindow", "Pause", Q_NULLPTR));
        highscoreButton->setText(QApplication::translate("MainWindow", "Highscores", Q_NULLPTR));
        menuSound->setTitle(QApplication::translate("MainWindow", "Options", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
