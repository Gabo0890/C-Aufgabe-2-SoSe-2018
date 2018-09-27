#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> //random integer
#include <QDebug>
#include <QApplication>
#include "game.h"
#include "button.h"

extern game * gamee;


enemies3::enemies3():QObject(),QGraphicsRectItem(){



    //set random position
    //random_numter ist x position
    int random_number = rand() % 900;
    int y=0;
    setPos(random_number,y);


//lastX=x;
//lastY=y;
//x=lastX;
//y=lastY;

    //draw the rect
    setRect(0,0,10,30);
    setBrush(Qt::blue);

    //connect timer bewegung
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



void enemies3::move(){

    //if enemie collides with player, destroy enemie
    QList<QGraphicsItem * > colliding_items = collidingItems();

    for(int i=0, n = colliding_items.size();i<n; i++){
        if(typeid(*(colliding_items[i])) ==  typeid(myPlayer)){
            //decreaselive the score
            gamee->score1->decreaseLive();

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


    setPos(x(),y()+3);
        if (pos().y() > 600){
            //increase the score
            gamee->health1->increaseScore();
            scene()->removeItem(this);
            delete this;
        }
        //haken bewegung
         if(pos().y() >100){
            setPos(x()+7,y()+3);
        }
         if(pos().y() >200){
            setPos(x()-6,y()+3);
        }
         if(pos().y() >300){
            setPos(x()+6,y()+3);
        }
         if(pos().y() >400){
            setPos(x()-9,y()+3);
        }
         if(pos().y() >500){
            setPos(x()+3,y()+3);
        }



}

void enemies3::stop()
{
    //stop den timer für enemy bewegung
    timer1->stop();

}

void enemies3::resume()
{
    //startet timer wieder für enemy bewegung
    timer1->start();

}


//Funktionen Speichern und Laden
//Positionen werden gespeichert
//LastX und LastY werden für die Koordinaten gebraucht
//für das Savegame in game.cpp

//Problem: pos().x() kann nicht an lastX,lastY übergeben werden

void enemies3::save(QFile &file)
{
    QTextStream out(&file);
    out << lastX << endl;
    out << lastY << endl;


}

void enemies3::load(QFile &file)
{
    QTextStream in(&file);
        int x,y;
        in >> x << endl;
        in >> y << endl;
        lastX=x;
        lastY=y;
        update();

}
