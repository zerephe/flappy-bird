#ifndef BIRD_H
#define BIRD_H
#include <QGraphicsPixmapItem>
#include <QObject>

class Bird: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Bird();
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    float getPos();

    //variables of 'bird'
    int direction;
    float acceleration = 0.0;
    bool keyFlag = true;
public slots:
    void accelerate();
    void moveDirection();
    void flapUp();
    void flapDown();
};

#endif // BIRD_H
