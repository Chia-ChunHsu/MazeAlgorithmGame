#ifndef STATUSMANAGER_H
#define STATUSMANAGER_H

#include <QWidget>
#include <QDebug>
#include <QMessageBox>
#include <opencv.hpp>
#define EMPTY 0
#define WALL 1
#define WATER 2
#define PATH 3
#define PEN 0
#define FILL 1
class StatusManager
{
public:
    StatusManager();
    void setColor(int type, cv::Scalar color);
    void setTool(int tool);
    cv::Scalar getColor();
    int getType();
    int getTool();
private:
    cv::Scalar _color;
    int _type;
    int _tool;
};


#endif // STATUSMANAGER_H
