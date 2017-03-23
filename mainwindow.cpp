#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    statusManager = new StatusManager();
    _size = 20;
    setWindowTitle("Maz Player");
    timer = new QTimer();
    timer->setInterval(50);

    Initial();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getMouseClickEvent(QPoint p)
{
    switch (statusManager->getTool())
    {
    case PEN:
    {
        cv::Rect r(p.x()*_size,p.y()*_size,_size,_size);
        cv::Mat temp;
        temp.create(_size,_size,CV_8UC3);
        temp.setTo(statusManager->getColor());
        temp.copyTo(map(r));
        mapObject.at<uchar>(p.y(),p.x()) = statusManager->getType();
        break;
    }
    case FILL:
    {
        //cv::Mat mask;
        cv::floodFill(map,cv::Point(p.x()*_size,p.y()*_size),statusManager->getColor());
        cv::floodFill(mapObject,cv::Point(p.x(),p.y()),cv::Scalar(statusManager->getType()));
        break;
    }
    }
    ShowOnLabel(ui->mapLabel,map);
}

void MainWindow::Initial()
{
    int _row = 400;
    int _col = 400;
    map = cv::Mat::zeros(_row,_col,CV_8UC3);
    mapObject = cv::Mat::zeros(_row/_size,_col/_size,CV_8UC1);
    ui->mapLabel->setEnable(false);
    ui->mapLabel->setScaleSize(_size);
    ShowOnLabel(ui->mapLabel,map);
    setObjectAttribute();

    connect(ui->mapLabel,SIGNAL(sendMousePoint(QPoint)),this,SLOT(getMouseClickEvent(QPoint)));
    connect(ui->wallPushButton,SIGNAL(sendButtonName(MyPushButton*)),this,SLOT(ObjectManager(MyPushButton*)));
    connect(ui->wallPushButton,SIGNAL(clicked(bool)),ui->wallPushButton,SLOT(sendButtonNameConnect()));
    connect(ui->WaterPushButton,SIGNAL(sendButtonName(MyPushButton*)),this,SLOT(ObjectManager(MyPushButton*)));
    connect(ui->WaterPushButton,SIGNAL(clicked(bool)),ui->WaterPushButton,SLOT(sendButtonNameConnect()));
    connect(ui->pathPushButton,SIGNAL(sendButtonName(MyPushButton*)),this,SLOT(ObjectManager(MyPushButton*)));
    connect(ui->pathPushButton,SIGNAL(clicked(bool)),ui->pathPushButton,SLOT(sendButtonNameConnect()));
    connect(ui->penButton,SIGNAL(sendButtonName(MyPushButton*)),this,SLOT(ObjectManager(MyPushButton*)));
    connect(ui->penButton,SIGNAL(clicked(bool)),ui->penButton,SLOT(sendButtonNameConnect()));
    connect(ui->fillButton,SIGNAL(sendButtonName(MyPushButton*)),this,SLOT(ObjectManager(MyPushButton*)));
    connect(ui->fillButton,SIGNAL(clicked(bool)),ui->fillButton,SLOT(sendButtonNameConnect()));
}

void MainWindow::setObjectAttribute()
{
    StatusManager *status1;
    status1 = new StatusManager();
    status1->setColor(WALL,cv::Scalar(0,50,120));
    ui->wallPushButton->setStatus(status1);
    StatusManager *status2;
    status2 = new StatusManager();
    status2->setColor(WATER,cv::Scalar(150,50,50));
    ui->WaterPushButton->setStatus(status2);
    StatusManager *statusPath;
    statusPath = new StatusManager();
    statusPath->setColor(PATH,cv::Scalar(250,210,210));
    ui->pathPushButton->setStatus(statusPath);
    StatusManager *statusPen;
    statusPen = new StatusManager();
    statusPen->setTool(PEN);
    ui->penButton->setStatus(statusPen);
    StatusManager *statusFill;
    statusFill = new StatusManager();
    statusFill->setTool(FILL);
    ui->fillButton->setStatus(statusFill);
    statusManager->setTool(ui->penButton->getToolType());
}

void MainWindow::ObjectManager(MyPushButton *button)
{
    if(button->parent()== ui->groupBox)
    {
        if(button->isChecked())
        {
            foreach(QPushButton *p,ui->groupBox->findChildren<QPushButton *>())
            {
                p->setChecked(false);
            }
            button->setChecked(true);
            statusManager->setColor(button->getStatus()->getType(),button->getStatus()->getColor());
            ui->mapLabel->setEnable(true);
        }
        else
            ui->mapLabel->setEnable(false);
    }
    else if(button->parent() == ui->groupBox_2)
    {
        foreach(QPushButton *p,ui->groupBox_2->findChildren<QPushButton *>())
        {
            p->setChecked(false);
        }
        button->setChecked(true);
        statusManager->setTool(button->getToolType());;
    }
}

void MainWindow::on_actionSaveMap_triggered()
{
    QString saveFileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                                                        QDir::currentPath()+"/untitled",
                                                        tr("Images (*.png *.bmp *.jpg)"));
    if(saveFileName.isEmpty())
        return;

    cv::imwrite(saveFileName.toStdString(),mapObject);
}

void MainWindow::on_actionLoadMap_triggered()
{
    QString openFileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                        QDir::currentPath(),
                                                        tr("Images (*.png *.xpm *.jpg)"));
    if(openFileName.isEmpty())
        return;
    mapObject = cv::imread(openFileName.toStdString(),0);
    //map
    for(int i=0;i<mapObject.rows;i++)
    {
        for(int j=0;j<mapObject.cols;j++)
        {
            cv::Rect ROI(j*_size,i*_size,_size,_size);
            cv::Mat temp;
            temp.create(_size,_size,CV_8UC3);
            cv::Scalar color;
            switch (mapObject.at<uchar>(i,j))
            {
            case WALL:
                color = cv::Scalar(0,50,120);
                break;
            case WATER:
                color = cv::Scalar(150,50,50);
                break;
            case PATH:
                color = cv::Scalar(250,210,210);
                break;
            }
            temp.setTo(color);
            temp.copyTo(map(ROI));
        }
    }
    ShowOnLabel(ui->mapLabel,map);
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::updateMap()
{
    int x = p1->getPos().getPosX();
    int y = p1->getPos().getPosY();
    int dir = p1->getDirection();
    QVector<bool> isWay;
    std::vector<Position> p;//[3]={Position(),Position(),Position()};
    switch(dir)
    {
    case DIR_TOP:
    {
        p.push_back(Position(x+1,y));
        p.push_back(Position(x,y-1));
        p.push_back(Position(x-1,y));
        break;
    }
    case DIR_DOWN:
    {
        p.push_back(Position(x-1,y));
        p.push_back(Position(x,y+1));
        p.push_back(Position(x+1,y));
        break;
    }
    case DIR_RIGHT:
    {
        p.push_back(Position(x,y+1));
        p.push_back(Position(x+1,y));
        p.push_back(Position(x,y-1));
        break;
    }
    case DIR_LEFT:
    {
        p.push_back(Position(x,y-1));
        p.push_back(Position(x-1,y));
        p.push_back(Position(x,y+1));
        break;
    }
    }
    for(int i=0;i<3;i++)
    {
        if(p[i].getPosX() >=_size || p[i].getPosY() >=_size || p[i].getPosX()<0 || p[i].getPosY()<0 )
            isWay.push_back(false);
        else if(mapObject.at<uchar>(p[i].getPosY(),p[i].getPosX())!= PATH)
            isWay.push_back(false);
        else
            isWay.push_back(true);
    }
    emit sendWay(isWay);
    cv::Rect r(p1->getPos().getPosX()*_size,p1->getPos().getPosY()*_size,_size,_size);
    cv::Mat temp;
    temp.create(_size,_size,CV_8UC3);
    temp.setTo(cv::Scalar(p1->getColor().blue(),p1->getColor().green(),p1->getColor().red()));
    cv::Mat mapClone = map.clone();
    temp.copyTo(mapClone(r));

    r = cv::Rect(tar->getPos().getPosX()*_size,tar->getPos().getPosY()*_size,_size,_size);
    temp.setTo(cv::Scalar(tar->getColor().blue(),tar->getColor().green(),tar->getColor().red()));
    temp.copyTo(mapClone(r));

    ShowOnLabel(ui->mapLabel,mapClone);

    if(p1->getPos().getPosX() == tar->getPos().getPosX()  && p1->getPos().getPosY() == tar->getPos().getPosY())
    {
        timer->stop();
        disconnect(timer,SIGNAL(timeout()),this,SLOT(updateMap()));
        ui->actionStart_Game->setEnabled(true);
    }
}

void MainWindow::on_actionStart_Game_triggered()
{
    p1 = new Player(DIR_TOP,Position(0,19));
    tar = new Target(Position(19,0));

    cv::Rect r(p1->getPos().getPosX()*_size,p1->getPos().getPosY()*_size,_size,_size);
    cv::Mat temp;
    temp.create(_size,_size,CV_8UC3);
    temp.setTo(cv::Scalar(p1->getColor().blue(),p1->getColor().green(),p1->getColor().red()));
    cv::Mat mapClone = map.clone();
    temp.copyTo(mapClone(r));


    r = cv::Rect(tar->getPos().getPosX()*_size,tar->getPos().getPosY()*_size,_size,_size);
    //cv::Mat temp;
    //temp.create(_size,_size,CV_8UC3);
    temp.setTo(cv::Scalar(tar->getColor().blue(),tar->getColor().green(),tar->getColor().red()));
    /*cv::Mat *///mapClone = map.clone();
    temp.copyTo(mapClone(r));

    ShowOnLabel(ui->mapLabel,mapClone);

    connect(this,SIGNAL(sendWay(QVector<bool>)),p1,SLOT(getWay(QVector<bool>)));
    connect(timer,SIGNAL(timeout()),this,SLOT(updateMap()));
    timer->start();
    ui->actionStart_Game->setEnabled(false);
}
