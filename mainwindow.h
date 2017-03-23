#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QFileDialog>
#include <QPushButton>
#include <QTimer>
#include <QMetaType>
#include <commonuse.h>
#include <opencv.hpp>
#include <statusmanager.h>
#include <target.h>
#include <mypushbutton.h>
#include <player.h>
#include <position.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
signals:
    void sendWay(QVector<bool>);

private slots:
    void getMouseClickEvent(QPoint p);

    void ObjectManager(MyPushButton *button);

    void on_actionSaveMap_triggered();

    void on_actionLoadMap_triggered();

    void on_actionExit_triggered();

    void updateMap();

    void on_actionStart_Game_triggered();

private:
    Ui::MainWindow *ui;
    cv::Mat map;
    cv::Mat mapObject;
    void Initial();
    void setObjectAttribute();
    StatusManager *statusManager;
    int _size;
    QTimer *timer;
    Player *p1;
    Target *tar;
};
Q_DECLARE_METATYPE(QVector<bool>)
#endif // MAINWINDOW_H
