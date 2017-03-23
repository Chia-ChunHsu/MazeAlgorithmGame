#ifndef QLABELMAP_H
#define QLABELMAP_H


#include <QLabel>
#include <QMouseEvent>
#include <QObject>
class QLabelMap :public QLabel
{
    Q_OBJECT
public:
    explicit QLabelMap(QWidget *parent  = 0);
    void setScaleSize(int size);
    void setEnable(bool enable);
signals:
    void sendMousePoint(QPoint p);
protected:
    void mousePressEvent(QMouseEvent *ev);
private:
    int _size;
    bool _enable;

};

#endif // QLABELMAP_H
