#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsPixmapItem>
#include <QObject>


class Score: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:

    void setScore(int score);

};

#endif // SCORE_H
