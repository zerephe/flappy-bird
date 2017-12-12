#include <QtWidgets>
#include <QtGui>
#include <QDebug>
#include <QGraphicsItem>
#include "gameover.h"
#include "game.h"


Gameover::Gameover(){
    setGameover();
    move(300, 150);
}

void Gameover::mousePressEvent(QMouseEvent* Event){
    goClicked();
}

void Gameover::setGameover(){
    //tryna add some widgets
    QPixmap pixmap(":/sprites/gameover.png");
    QPalette pal;
    pal.setBrush(pal.Normal, pal.Window, QBrush(pixmap));
    pal.setBrush(pal.Inactive, pal.Window, QBrush(pixmap));
    setPalette(pal);
    setMask(pixmap.mask());
    resize(200, 45);
}

void Gameover::setRestart(){
    QPixmap pixmap(":/sprites/message.png");
    QPalette pal;
    pal.setBrush(pal.Normal, pal.Window, QBrush(pixmap));
    pal.setBrush(pal.Inactive, pal.Window, QBrush(pixmap));
    setPalette(pal);
    setMask(pixmap.mask());
    resize(pixmap.width(), pixmap.height());
}
