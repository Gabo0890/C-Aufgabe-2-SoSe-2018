#include "player.h"
#include <QKeyEvent>
#include "enemies.h"
#include <QGraphicsScene>

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
  /*  //create enemy
    enemies * enemy = new enemies();
    scene()->addItem(enemy);
*/
}



