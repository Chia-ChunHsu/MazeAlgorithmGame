#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QObject>
#include <QPushButton>
#include <statusmanager.h>
#include <opencv.hpp>


class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyPushButton(QWidget *parent = 0);
    void setID(int ID);
    void setStatus(StatusManager *status);
    //void setTool(int tool);
    int getStatusType();
    int getToolType();
    cv::Scalar getStatusColor();
    StatusManager* getStatus();

signals:
    void sendID(int);
    void sendButtonName(MyPushButton *);

public slots:
    void sendIDConnect();
    void sendButtonNameConnect();
private:
    int _ID;
    StatusManager *_status;
};

#endif // MYPUSHBUTTON_H
