#include <QSoundEffect>
#include <QObject>
#include "soundeffects.h"


Sounds::Sounds(){
    //on hit sound
    onHit.setSource(QUrl::fromLocalFile(":/sounds/hit.wav"));

    //on Die sound
    onDie.setSource(QUrl::fromLocalFile(":/sounds/die.wav"));

    //on Pass sound
    onPass.setSource(QUrl::fromLocalFile(":/sounds/point.wav"));

    //on Clap Sound
    onClap.setSource(QUrl::fromLocalFile(":/sounds/wing.wav"));
}

void Sounds::onHitSound(){
    onHit.play();
}

void Sounds::onDieSound(){
    onDie.play();
}

void Sounds::onPassSound(){
    onPass.play();
}

void Sounds::onClapSound(){
    onClap.play();
}
