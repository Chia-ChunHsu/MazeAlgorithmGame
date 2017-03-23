/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "mypushbutton.h"
#include "qlabelmap.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLoadMap;
    QAction *actionSaveMap;
    QAction *actionExit;
    QAction *actionStart_Game;
    QWidget *centralWidget;
    QGroupBox *groupBox;
    MyPushButton *wallPushButton;
    MyPushButton *WaterPushButton;
    MyPushButton *pathPushButton;
    QLabelMap *mapLabel;
    QGroupBox *groupBox_2;
    MyPushButton *penButton;
    MyPushButton *fillButton;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(620, 500);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(620, 500));
        MainWindow->setMaximumSize(QSize(620, 500));
        actionLoadMap = new QAction(MainWindow);
        actionLoadMap->setObjectName(QStringLiteral("actionLoadMap"));
        actionSaveMap = new QAction(MainWindow);
        actionSaveMap->setObjectName(QStringLiteral("actionSaveMap"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionStart_Game = new QAction(MainWindow);
        actionStart_Game->setObjectName(QStringLiteral("actionStart_Game"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(420, 20, 91, 411));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        groupBox->setMinimumSize(QSize(50, 0));
        groupBox->setMaximumSize(QSize(150, 16777215));
        groupBox->setCheckable(false);
        wallPushButton = new MyPushButton(groupBox);
        wallPushButton->setObjectName(QStringLiteral("wallPushButton"));
        wallPushButton->setGeometry(QRect(10, 22, 75, 23));
        wallPushButton->setCheckable(true);
        wallPushButton->setChecked(false);
        wallPushButton->setAutoDefault(false);
        wallPushButton->setFlat(true);
        WaterPushButton = new MyPushButton(groupBox);
        WaterPushButton->setObjectName(QStringLiteral("WaterPushButton"));
        WaterPushButton->setGeometry(QRect(10, 51, 75, 23));
        WaterPushButton->setCheckable(true);
        WaterPushButton->setChecked(false);
        WaterPushButton->setAutoDefault(false);
        WaterPushButton->setFlat(true);
        pathPushButton = new MyPushButton(groupBox);
        pathPushButton->setObjectName(QStringLiteral("pathPushButton"));
        pathPushButton->setGeometry(QRect(10, 80, 75, 23));
        pathPushButton->setCheckable(true);
        pathPushButton->setFlat(true);
        mapLabel = new QLabelMap(centralWidget);
        mapLabel->setObjectName(QStringLiteral("mapLabel"));
        mapLabel->setGeometry(QRect(10, 30, 400, 400));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(mapLabel->sizePolicy().hasHeightForWidth());
        mapLabel->setSizePolicy(sizePolicy2);
        mapLabel->setMinimumSize(QSize(400, 400));
        mapLabel->setMaximumSize(QSize(400, 400));
        mapLabel->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(520, 20, 91, 411));
        penButton = new MyPushButton(groupBox_2);
        penButton->setObjectName(QStringLiteral("penButton"));
        penButton->setGeometry(QRect(10, 20, 75, 23));
        penButton->setCheckable(true);
        penButton->setChecked(true);
        penButton->setFlat(true);
        fillButton = new MyPushButton(groupBox_2);
        fillButton->setObjectName(QStringLiteral("fillButton"));
        fillButton->setGeometry(QRect(10, 50, 75, 23));
        fillButton->setCheckable(true);
        fillButton->setFlat(true);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 620, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionLoadMap);
        menuFile->addAction(actionSaveMap);
        menuFile->addSeparator();
        menuFile->addAction(actionStart_Game);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);

        retranslateUi(MainWindow);

        wallPushButton->setDefault(false);
        WaterPushButton->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionLoadMap->setText(QApplication::translate("MainWindow", "LoadMap", 0));
        actionSaveMap->setText(QApplication::translate("MainWindow", "SaveMap", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        actionStart_Game->setText(QApplication::translate("MainWindow", "Start Game", 0));
        actionStart_Game->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Object", 0));
        wallPushButton->setText(QApplication::translate("MainWindow", "Wall", 0));
        WaterPushButton->setText(QApplication::translate("MainWindow", "Water", 0));
        pathPushButton->setText(QApplication::translate("MainWindow", "Path", 0));
        mapLabel->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Tool", 0));
        penButton->setText(QApplication::translate("MainWindow", "Pen", 0));
        fillButton->setText(QApplication::translate("MainWindow", "Fill", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
