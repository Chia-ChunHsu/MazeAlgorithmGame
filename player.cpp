#include "player.h"

Player::Player()
{
    _direction = DIR_TOP;
    _pos = Position();
    _color = QColor(0,0,255);
}

Player::Player(int direction, Position pos)
{
    _direction = direction;
    _pos = pos;
    _color = QColor(0,0,255);
}

Position Player::getPos()
{
    return _pos;
}

int Player::getDirection()
{
    return _direction;
}

QColor Player::getColor()
{
    return _color;
}

void Player::getWay(QVector<bool> path)
{
    Distinguish(path,RIGHT_WALL_FOLLOWING);
}

void Player::Distinguish(QVector<bool> path, int Method)
{
    std::vector<bool> _path;
    for(int i=0;i<path.count();i++)
        _path.push_back(path[i]);
    DistinguishDirection dir(_path);
    switch (Method) {
    case RIGHT_WALL_FOLLOWING:
        ChangeDirection(dir.DisinguishRighWallFollowing());
        break;
    default:
        ChangeDirection(dir.DisinguishRighWallFollowing());
        break;
    }
    Move();
}

void Player::ChangeDirection(int motion)
{
    switch (motion) {
    case TURNRIGHT:
        _direction++;
        _direction = _direction%4;
        break;
    case MOVEFONTAL:
        //do nothing
        break;
    case TURNLEFT:
        _direction+=4;
        _direction--;
        _direction = _direction%4;
        break;
    case TURNAROUND:
        _direction++;
        _direction = _direction%4;
        _direction++;
        _direction = _direction%4;
        break;
    }
}

void Player::Move()
{
    int x = _pos.getPosX();
    int y = _pos.getPosY();
    switch(_direction)
    {
    case DIR_TOP:
    {
        y--;
        break;
    }
    case DIR_DOWN:
    {
        y++;
        break;
    }
    case DIR_RIGHT:
    {
        x++;
        break;
    }
    case DIR_LEFT:
    {
        x--;
        break;
    }
    }
    _pos.setPosition(x,y);
}
