#ifndef PLAYER_H
#define PLAYER_H
//MOTION
#define TURNRIGHT  0
#define MOVEFONTAL   1
#define TURNLEFT    2
#define TURNAROUND  3

//DIRECTION
#define DIR_TOP 0
#define DIR_RIGHT    1
#define DIR_DOWN   2
#define DIR_LEFT    3
//METHOD
#define RIGHT_WALL_FOLLOWING 0


#include <QObject>
#include <QColor>
#include <QDebug>
#include <QVector>
#include <distinguishdirection.h>
#include <position.h>


//*************************
//Definition of QVector<bool> format:
//    position 0 : right
//    position 1 : frontal
//    position 2 : left
//*************************
//*************************
//Definition of Method format:
//    Method 0 : RightWallFollowing
//    Method 1 : Not Defined
//    Method 2 : Not Defined
//*************************

class Player:public QObject
{
    Q_OBJECT
public:
    Player();
    Player(int direction,Position pos);
    Position getPos();
    int getDirection();
    QColor getColor();
private slots:
    void getWay(QVector<bool> path);
private:
    int _direction;
    Position _pos;
    void Distinguish(QVector<bool> path, int Method);
    void ChangeDirection(int motion);
    void Move();
    QColor _color;
};


#endif // PLAYER_H
