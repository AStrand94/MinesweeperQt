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
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsView;
    QHBoxLayout *horizontalLayout;
    QLCDNumber *lcdNumber;
    QPushButton *clearButton;
    QPushButton *pauseButton;
    QPushButton *highscoreButton;
    QLCDNumber *lcdNumber_1;
    QMenuBar *menuBar;
    QMenu *menuSound;
    QMenu *menuOptions;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(600, 717);
        MainWindow->setMinimumSize(QSize(600, 700));
        MainWindow->setMaximumSize(QSize(624, 800));
        actionMute = new QAction(MainWindow);
        actionMute->setObjectName(QStringLiteral("actionMute"));
        actionMute->setCheckable(true);
        actionImmortal = new QAction(MainWindow);
        actionImmortal->setObjectName(QStringLiteral("actionImmortal"));
        actionImmortal->setCheckable(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setMinimumSize(QSize(600, 600));
        graphicsView->setMaximumSize(QSize(600, 600));

        verticalLayout->addWidget(graphicsView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));

        horizontalLayout->addWidget(lcdNumber);

        clearButton = new QPushButton(centralWidget);
        clearButton->setObjectName(QStringLiteral("clearButton"));

        horizontalLayout->addWidget(clearButton);

        pauseButton = new QPushButton(centralWidget);
        pauseButton->setObjectName(QStringLiteral("pauseButton"));

        horizontalLayout->addWidget(pauseButton);

        highscoreButton = new QPushButton(centralWidget);
        highscoreButton->setObjectName(QStringLiteral("highscoreButton"));

        horizontalLayout->addWidget(highscoreButton);

        lcdNumber_1 = new QLCDNumber(centralWidget);
        lcdNumber_1->setObjectName(QStringLiteral("lcdNumber_1"));

        horizontalLayout->addWidget(lcdNumber_1);


        verticalLayout->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 22));
        menuSound = new QMenu(menuBar);
        menuSound->setObjectName(QStringLiteral("menuSound"));
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName(QStringLiteral("menuOptions"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuSound->menuAction());
        menuBar->addAction(menuOptions->menuAction());
        menuSound->addAction(actionMute);
        menuOptions->addAction(actionImmortal);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionMute->setText(QApplication::translate("MainWindow", "Mute", Q_NULLPTR));
        actionImmortal->setText(QApplication::translate("MainWindow", "Immortal", Q_NULLPTR));
        clearButton->setText(QApplication::translate("MainWindow", "New Game", Q_NULLPTR));
        pauseButton->setText(QApplication::translate("MainWindow", "Pause", Q_NULLPTR));
        highscoreButton->setText(QApplication::translate("MainWindow", "Highscores", Q_NULLPTR));
        menuSound->setTitle(QApplication::translate("MainWindow", "Sound", Q_NULLPTR));
        menuOptions->setTitle(QApplication::translate("MainWindow", "Options", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
