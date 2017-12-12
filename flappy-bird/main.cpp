#include <QApplication>
#include "game.h"


Game *gameScene;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    gameScene = new Game();
    gameScene->show();

    return a.exec();
}
