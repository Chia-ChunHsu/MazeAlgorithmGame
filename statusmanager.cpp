#include "statusmanager.h"

StatusManager::StatusManager()
{

}

void StatusManager::setTool(int tool)
{
    _tool = tool;
}

void StatusManager::setColor(int type, cv::Scalar color)
{
    _type = type;
    _color = color;
}

cv::Scalar StatusManager::getColor()
{
    return _color;
}

int StatusManager::getType()
{
    return _type;
}

int StatusManager::getTool()
{
    return _tool;
}
