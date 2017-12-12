#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QDebug>
#include <QTimer>
#include "barriers.h"
#include "bird.h"
#include "game.h"
#include "score.h"


extern Game *gameScene; //external call of object Game
Barriers::Barriers(){
    setPixmap(QPixmap(":/sprites/pipe-green.png"));
    setCacheMode(QGraphicsItem::ItemCoordinateCache);
    timer->start(15);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
}

void Barriers::move(){
    //Collision detection
    QList<QGraphicsItem *> itemsCollide = collidingItems();
    foreach(QGraphicsItem *item, itemsCollide){
        if(typeid(*item) == typeid(Bird) && !gameScene->collision){
            gameScene->effects->onHitSound();
            gameScene->effects->onDieSound();

            //'disabling' keypress event
            gameScene->bird->direction = -1;
            gameScene->bird->keyFlag = false;

            //disable barriers creation
            gameScene->bird->disconnect(gameScene->timer2, SIGNAL(timeout()), gameScene, SLOT(barriers()));

            gameScene->collision = true;
            gameScene->gameOver();
        }
    }

    if(gameScene->collision == false){//if bird isn't collided
        setPos(x()-2, y());
    }

    //scoring
    if(pos().x() == gameScene->bird->getPos()){
        gameScene->count++;
        if(gameScene->count%2 == 0){
            gameScene->score->setScore(gameScene->count/2);
            gameScene->effects->onPassSound();
        }
    }

    if(pos().x() + pixmap().width() < 0){
        gameScene->columns->removeOne(this);
        scene()->removeItem(this);
        delete this;
    }
}

