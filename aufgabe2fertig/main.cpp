#include <QApplication>
#include "game.h"


game * gamee;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    gamee = new game();
    gamee->show();


    return a.exec();
}
