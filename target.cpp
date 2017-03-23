#include "target.h"

Target::Target()
{
    _pos = Position();
    _color = QColor(0,255,0);
}

Target::Target(Position p)
{
    _pos = p;
    _color = QColor(0,255,0);
}

Position Target::getPos()
{
    return _pos;
}

QColor Target::getColor()
{
    return _color;
}
