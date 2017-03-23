#include "mypushbutton.h"

MyPushButton::MyPushButton(QWidget *parent) : QPushButton(parent)
{

}

void MyPushButton::setID(int ID)
{
    _ID = ID;
}

void MyPushButton::setStatus(StatusManager *status)
{
    _status = status;
}

int MyPushButton::getToolType()
{
    return _status->getTool();
}

cv::Scalar MyPushButton::getStatusColor()
{
    return _status->getColor();
}

StatusManager *MyPushButton::getStatus()
{
    return _status;
}

void MyPushButton::sendIDConnect()
{
    emit sendID(_ID);
}

void MyPushButton::sendButtonNameConnect()
{
    emit sendButtonName(this);
}
