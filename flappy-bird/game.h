#ifndef GAME_H
#define GAME_H
#include <QApplication>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QObject>
#include <QGraphicsPixmapItem>
#include "bird.h"
#include "score.h"
#include "soundeffects.h"
#include "gameover.h"
#include "barriers.h"

class Game: public QGraphicsView{
    Q_OBJECT

public:
    Game(QWidget *parent = 0);

    QGraphicsScene *scene;
    Score *score;
    Bird *bird;
    Sounds *effects;
    Gameover *pop;
    Barriers *topBar;
    Barriers *bottomBar;

    //'bird's' timer events
    QTimer *timer;
    QTimer *timer2;
    bool collision = false;
    int count = 0;

    QList<Barriers*> *columns = new QList<Barriers*>();
    QList<Score*> *scores = new QList<Score*>();


    void gameOver();

public slots:
    void restartGame();
    void barriers();
};

#endif // GAME_H
