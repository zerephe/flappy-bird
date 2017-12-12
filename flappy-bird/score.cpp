#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QObject>
#include <QPainter>
#include <QDebug>
#include <QString>
#include "score.h"
#include "game.h"

extern Game *gameScene;
void Score::setScore(int score){
    int wide = -5, i = 0;
    QString scoreStr = QString::number(score);
    while(i < scoreStr.length()){
        if(i == 0){
             gameScene->scores->at(i)->setPixmap(QPixmap(":/sprites/"+scoreStr[i]+".png"));
        }
        else{
            if(gameScene->scores->size() < scoreStr.length()){
                gameScene->scores->append(new Score());
                gameScene->scores->at(i)->setPixmap(QPixmap(":/sprites/"+scoreStr[i]+".png"));
                gameScene->scores->at(i)->setPos(gameScene->scene->width()/2 + wide, 100);
                gameScene->scores->at(i)->setZValue(1);
                gameScene->scene->addItem(gameScene->scores->at(i));
            }
            else{
                gameScene->scores->at(i)->setPixmap(QPixmap(":/sprites/"+scoreStr[i]+".png"));
                gameScene->scores->at(i)->setPos(gameScene->scene->width()/2 + wide, 100);
            }
        }
        wide+=15;
        i++;
    }

}

