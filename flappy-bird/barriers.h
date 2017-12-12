#ifndef BARRIERS_H
#define BARRIERS_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>


class Barriers: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Barriers();
    QTimer *timer = new QTimer();

public slots:
    void move();
    //void onPassSound();
    //void onHitSound();
};

#endif // BARRIERS_H
