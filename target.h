#ifndef TARGET_H
#define TARGET_H
#include <position.h>
#include <QColor>
class Target
{
public:
    Target();
    Target(Position p);
    Position getPos();
    QColor getColor();
private:
    Position _pos;
    QColor _color;
};

#endif // TARGET_H
