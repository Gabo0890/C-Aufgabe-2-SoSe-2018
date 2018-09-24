#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> //random integer
#include <QDebug>
#include <QApplication>
#include "game.h"
#include "enemies.h"
#include "button.h"

extern game * gamee;




enemies::enemies():QObject(),QGraphicsRectItem(){

    //set random position
    int random_number = rand() % 700;
    setPos(random_number,0);

    //draw the rect
    setRect(0,0,35,35);

    //connect
    timer1 = new QTimer(this);
    connect(timer1,SIGNAL(timeout()),this,SLOT(move()));
    timer1->start(50);


connect(gamee->stopbutton,SIGNAL(clicked()),SLOT(stop()));

//resume connect
connect(gamee->resumebutton,SIGNAL(clicked()),SLOT(resume()));
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

void enemies::stop()
{
    timer1->stop();
}

void enemies::resume()
{
    timer1->start();
}

//um timer zu reaktivieren
//void enemies::resume()

