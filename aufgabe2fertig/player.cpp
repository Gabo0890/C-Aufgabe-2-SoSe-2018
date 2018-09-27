#include "player.h"
#include <QKeyEvent>
#include "enemies.h"
#include <QGraphicsScene>
//#include <Qtimer>

void myPlayer::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left){
        if (pos().x() > 0)
        setPos(x()-10,y());
    }
    if(event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 800)
        setPos(x()+10,y());
    }
}

void myPlayer::spawn()
{
    //create enemy
    enemies * enemy = new enemies();
    scene()->addItem(enemy);


}

void myPlayer::spawn1()
{
    enemies1 * enemy1 = new enemies1();
    scene()->addItem(enemy1);
}

void myPlayer::spawn2()
{
    enemies2 * enemy2 = new enemies2();
    scene()->addItem(enemy2);
}

void myPlayer::spawn3()
{
    enemies3 * enemy3 = new enemies3();
    scene()->addItem(enemy3);
}



