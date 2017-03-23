#ifndef POSITION_H
#define POSITION_H

class Position
{
public:
    Position();
    Position(int x,int y);
    void setPosition(int x,int y);
    int getPosX();
    int getPosY();
private:
    int _x;
    int _y;
};

#endif // POSITION_H
