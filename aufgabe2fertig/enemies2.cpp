#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> //random integer
#include <QDebug>
#include <QApplication>
#include "game.h"
#include "button.h"

extern game * gamee;


enemies2::enemies2():QObject(),QGraphicsRectItem(){



    //set random position
    int random_number = rand() % 900;
    setPos(random_number,0);



    //draw the rect
    setRect(0,30,40,40);
    setBrush(Qt::magenta);

    //connect
    timer1 = new QTimer(this);
    connect(timer1,SIGNAL(timeout()),this,SLOT(move()));
    timer1->start(50);

//SLOT stop() mit Stopbutton verbunden (in game.cpp)
connect(gamee->stopbutton,SIGNAL(clicked()),SLOT(stop()));
//SLOT stop() mit Resumebutton verbunden (in game.cpp)
connect(gamee->resumebutton,SIGNAL(clicked()),SLOT(resume()));
/*//SLOT save() mit Savebutton verbunden (in game.cpp)
connect(gamee->savebutton,SIGNAL(clicked()),SLOT(save()));
//SLOT load() mit Loadbutton verbunden (in game.cpp)
connect(gamee->loadbutton,SIGNAL(clicked()),SLOT(save()));
*/
}



void enemies2::move(){

    //if enemie collides with player, destroy enemie
    QList<QGraphicsItem * > colliding_items = collidingItems();

    for(int i=0, n = colliding_items.size();i<n; i++){
        if(typeid(*(colliding_items[i])) ==  typeid(myPlayer)){
            //decreaselive the score
            gamee->score1->increaselive();

            //löschen von liveicon
            gamee->liveIcon1->deleteIcon();

            //TODO: stops enemie(beide timer) + player

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
    //TODO:zickzack bewegung
    //TODO: speichern von positionen-->switch case für positionen
    setPos(x(),y()+5);
        if (pos().y() > 600){
            //increase the score
            gamee->health1->increaseScore();
            scene()->removeItem(this);
            delete this;
        }

}

void enemies2::stop()
{
    //stop den timer für enemy bewegung
    timer1->stop();

}

void enemies2::resume()
{
    //startet timer wieder für enemy bewegung
    timer1->start();
}


//Funktionen Speichern und Laden
//Positionen werden gespeichert
//LastX und LastY werden für die Koordinaten gebraucht
//für das Savegame in game.cpp
void enemies2::save(QFile &file)
{
    QTextStream out(&file);
    out >> lastX >> endl;
    out >> lastY >> endl;
}

void enemies2::load(QFile &file)
{
    QTextStream in(&file);
        int x,y;
        in >> x << endl;
        in >> y << endl;
        lastX=x;
        lastY=y;
        update();

}
