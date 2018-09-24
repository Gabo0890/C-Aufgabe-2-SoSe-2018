#include "enemies.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> //random integer
#include <QDebug>
#include <QApplication>
#include "game.h"

extern game * gamee;




enemies::enemies():QObject(),QGraphicsRectItem(){

    //set random position
    int random_number = rand() % 700;
    setPos(random_number,0);

    //draw the rect
    setRect(0,0,35,35);

    //connect
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);

}



void enemies::move(){

    //if enemie collides with player, destroy enemie
    QList<QGraphicsItem * > colliding_items = collidingItems();

    for(int i=0, n = colliding_items.size();i<n; i++){
        if(typeid(*(colliding_items[i])) ==  typeid(myPlayer)){
            //decreaselive the score
            gamee->score1->decreaseLive();
            //löschen von liveicon
            //gamee->liveIcon1->deleteIcon();
            //remove enemie
            scene()->removeItem(this);
            //delete enemie
            delete this;
            //sollte eigentlich die anwendung beenden, wenn der counter größer als 4ist
            if( i>4){
             QApplication::quit();
            }
            return;

        }
    }
    //move enemies down
    setPos(x(),y()+5);
        if (pos().y() > 600){
            //increase the score
            gamee->health1->increaseScore();
            scene()->removeItem(this);
            delete this;

           }
}
