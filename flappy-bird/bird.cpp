#include <QKeyEvent>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QDebug>
#include <QTimer>
#include <stdlib.h>
#include "bird.h"
#include "game.h"


QTimer *timer3 = new QTimer();
Bird::Bird(){
    setPixmap(QPixmap(":/sprites/yellowbird-midflap.png"));
    setPos(300, 340);
    setCacheMode(QGraphicsItem::ItemCoordinateCache);
}

void Bird::moveDirection(){
    if (direction == -1){
        setPixmap(QPixmap(":/sprites/yellowbird-midflap.png"));
        QTimer::singleShot(500, this, SLOT(accelerate()));
        if(pos().y() + pixmap().height() < scene()->height()){
            setPos(x(), y()-1 - acceleration);
        }
        setTransformOriginPoint(pixmap().width()/2, pixmap().height()/2);
        if(acceleration < -3.5)
            setRotation(-35 - acceleration*12);
    }
    else if(direction == 1){
        timer3->singleShot(100, this, SLOT(flapUp()));
        timer3->singleShot(100, this, SLOT(flapDown()));
        QTimer::singleShot(500, this, SLOT(accelerate()));
        if(pos().y() > 0){
            setPos(x(), y()-3.5);
        }
        setTransformOriginPoint(pixmap().width()/2, pixmap().height()/2);
        setRotation(-10);
    }
}

void Bird::flapUp(){
    setPixmap(QPixmap(":/sprites/yellowbird-upflap.png"));
}

void Bird::flapDown(){
    setPixmap(QPixmap(":/sprites/yellowbird-downflap.png"));
}

void Bird::accelerate(){
    if(direction == 1 && acceleration < 1.5){
        acceleration = 1.5;
    }
    else if(acceleration >= -10) acceleration -= 0.14;

}

void Bird::keyPressEvent(QKeyEvent *event){
    if(keyFlag == true){
        switch(event->key()){
            case Qt::Key_Up:
                direction = 1;
                break;

            case Qt::Key_Space:
                direction = 1;
                break;

        }
    }
    else{
            event->ignore();
        }


//        case Qt::Key_Down:
//            direction = -1;
//            break;
}

void Bird::keyReleaseEvent(QKeyEvent *event){
    switch(event->key()){
        case Qt::Key_Up:
            direction = -1;
            break;
        case Qt::Key_Space:
            direction = -1;
            break;
    }
}

float Bird::getPos(){
    return pos().x();
}

