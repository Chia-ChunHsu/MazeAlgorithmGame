#include "position.h"

Position::Position()
{
    _x = 0;
    _y = 0;
}

Position::Position(int x, int y)
{
    _x = x;
    _y = y;
}

void Position::setPosition(int x, int y)
{
    _x = x;
    _y = y;
}

int Position::getPosX()
{
    return _x;
}

int Position::getPosY()
{
    return _y;
}
