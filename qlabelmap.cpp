#include "qlabelmap.h"

QLabelMap::QLabelMap(QWidget *parent):QLabel(parent)
{
    _enable = false;
    _size = 0;
}

void QLabelMap::setScaleSize(int size)
{
    _size = size;
}

void QLabelMap::setEnable(bool enable)
{
    _enable = enable;
}

void QLabelMap::mousePressEvent(QMouseEvent *ev)
{
    if(_enable == false  || ev->button() != Qt::LeftButton)
        return;
    QPoint position(ev->pos().x()/_size,ev->pos().y()/_size);
    emit sendMousePoint(position);
}
