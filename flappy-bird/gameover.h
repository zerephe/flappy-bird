#ifndef GAMEOVER_H
#define GAMEOVER_H
#include <QtWidgets>
#include <QtGui>

class Gameover: public QWidget{
    Q_OBJECT

public:
    Gameover();
    void setGameover();
public slots:
    void setRestart();
signals:
    void goClicked();

protected:
    void mousePressEvent(QMouseEvent* event);
};

#endif // GAMEOVER_H
