#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> //random integer
#include <QDebug>
#include <QApplication>
#include "game.h"
#include "button.h"


extern game * gamee;



enemies::enemies():QObject(),QGraphicsRectItem(){



    //set random position
    int random_number = rand() % 900;
    setPos(random_number,0);



    //draw the rect
    setRect(0,30,15,15);
    setBrush(Qt::darkBlue);

    //connect
    timer1 = new QTimer(this);
    connect(timer1,SIGNAL(timeout()),this,SLOT(move()));
    timer1->start(50);

//SLOT stop() mit Stopbutton verbunden (in game.cpp)
connect(gamee->stopbutton,SIGNAL(clicked()),SLOT(stop()));
//SLOT stop() mit Resumebutton verbunden (in game.cpp)
connect(gamee->resumebutton,SIGNAL(clicked()),SLOT(resume()));
}



void enemies::move(){

    //if enemie collides with player, destroy enemie
    QList<QGraphicsItem * > colliding_items = collidingItems();

    for(int i=0, n = colliding_items.size();i<n; i++){
        if(typeid(*(colliding_items[i])) ==  typeid(myPlayer)){


            /*    //stoppt momentan nur das gameobjekt, mit welchem kollidiert wurde
            QTime timer2 = QTime::currentTime().addSecs(1);
            while(QTime::currentTime()<timer2)
                QCoreApplication::processEvents(QEventLoop::AllEvents, 100);*/


            //decreaselive the score
            gamee->score1->decreaseLive();

            //TODO: stops enemie timer(beide)

            //remove enemie
            scene()->removeItem(this);


            //delete enemie
            delete this;

            return;

        }
    }

    //move enemies down
    //TODO:Speichern von Positionen-->Switch case mit positionen
    setRotation(y()+10);
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
    //stop den timer für enemy bewegung
    timer1->stop();
}

void enemies::resume()
{
    //startet timer wieder für enemy bewegung
    timer1->start();
}


//Funktionen Speichern und Laden
//Positionen werden gespeichert
//LastX und LastY werden für die Koordinaten gebraucht
//für das Savegame in game.cpp
void enemies::save(QFile &file)
{
    QTextStream out(&file);
    out >> lastX >> endl;
    out >> lastY >> endl;
}

void enemies::load(QFile &file)
{
    QTextStream in(&file);
        int x,y;
        in >> x << endl;
        in >> y << endl;
        lastX=x;
        lastY=y;
        update();

}
