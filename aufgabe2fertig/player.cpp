#include "player.h"
#include <QKeyEvent>
#include "enemies.h"
#include <QGraphicsScene>
#include <Qtimer>

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



