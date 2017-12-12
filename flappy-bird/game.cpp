#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMediaPlayer>
#include <QGraphicsProxyWidget>
#include <QtGui>
#include <QWidget>
#include <QtWidgets>
#include <QObject>
#include "bird.h"
#include "game.h"
#include "barriers.h"
#include "gameover.h"
#include "score.h"
#include "soundeffects.h"



Game::Game(QWidget *parent){

    //setting background
    setBackgroundBrush(QBrush(QImage(":/sprites/background-day.png")));
    setFrameStyle(0);

    //adding scene
    scene = new QGraphicsScene();

    //adding rect object
    bird = new Bird();
    bird->setFlag(QGraphicsItem::ItemIsFocusable);
    bird->setFocus();
    scene->addItem(bird);

    //timer events of 'bird'
    timer = new QTimer();
    timer->start(10);
    bird->connect(timer, SIGNAL(timeout()), bird, SLOT(moveDirection()));
    //barriers appearing
    timer2 = new QTimer();
    timer2->start(2000);
    connect(timer2, SIGNAL(timeout()), this, SLOT(barriers()));

    //setting view
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,500);
    scene->setSceneRect(0, 0, 800, 500);

    //setting score
    scores->append(new Score());
    scores->at(0)->setPixmap(QPixmap(":/sprites/0.png"));
    scores->at(0)->setPos(scene->width()/2 - 15, 100);
    scores->at(0)->setZValue(1);
    scene->addItem(scores->at(0));


    //setting icon
    setWindowIcon(QIcon(":/sprites/flappy.ico"));

    //making sounds
    effects = new Sounds();

    //connecting gameover and restart
    pop = new Gameover();
    connect(pop, SIGNAL(goClicked()), this, SLOT(restartGame()), Qt::QueuedConnection);
}

bool isGO = false;
QGraphicsProxyWidget *proxy;
void Game::gameOver(){

    //on gameover
    if(!isGO){
       proxy = scene->addWidget(pop);
       isGO=true;
    }

    else {
        pop->setGameover();
        scene->addItem(proxy);
    }
    QTimer::singleShot(1500,pop, SLOT(setRestart()));
}

void Game::restartGame(){
    QList<QGraphicsItem*> list =scene->items();

        for(int i=0;i<columns->length();i++){
            scene->removeItem(columns->at(i));
            delete columns->at(i);
        }
        for(int i = 0; i < scores->length(); i++){
            scene->removeItem(scores->at(i));
            delete scores->at(i);
        }

    //bird initializing
    bird->setPos(300, 340);
    bird->direction = 0;
    bird->keyFlag = true;
    bird->setRotation(0);
    bird->acceleration = 0.0;
    bird->setFlag(QGraphicsItem::ItemIsFocusable);
    bird->setFocus();

    //initializing score
    scores->clear();
    scores->append(new Score());
    scores->at(0)->setPixmap(QPixmap(":/sprites/0.png"));
    scores->at(0)->setPos(scene->width()/2 - 15, 100);
    scores->at(0)->setZValue(1);
    scene->addItem(scores->at(0));
    count = 0;

    collision = false;
    connect(timer2, SIGNAL(timeout()), this, SLOT(barriers()));
    scene->removeItem(proxy);
    columns->clear();
}

void Game::barriers(){
    int random = rand() % 200 + 120;
    topBar = new Barriers();
    bottomBar = new Barriers();
    columns->append(topBar);
    columns->append(bottomBar);
    topBar->setRotation(180);
    scene->addItem(topBar);
    scene->addItem(bottomBar);
    topBar->setPos(880, random);
    bottomBar->setPos(830, random + 100);

}
