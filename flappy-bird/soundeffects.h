#ifndef SOUNDEFFECTS_H
#define SOUNDEFFECTS_H
#include <QSoundEffect>
#include <QObject>


class Sounds: public QSoundEffect{
    Q_OBJECT
public:
    Sounds();
    QSoundEffect onHit;
    QSoundEffect onDie;
    QSoundEffect onPass;
    QSoundEffect onClap;

public slots:
    void onHitSound();
    void onDieSound();
    void onPassSound();
    void onClapSound();
};

#endif // SOUNDEFFECTS_H
