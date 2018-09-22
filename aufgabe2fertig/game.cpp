#include "game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "enemies.h"
//#include "liveicon.h"

game::game(QWidget *parent)
{
    //create scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);

    //
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    //create player to put into scene
    player = new myPlayer();
    player->setRect(0,0,100,20);
    player->setPos(350,500);

    //create liveIcon1
    liveIcon1 = new liveIcon();
    liveIcon1->setRect(0,0,10,10);
    liveIcon1->setPos(45,6);

    //create liveIcon2
    liveIcon2 = new liveIcon();
    liveIcon2->setRect(0,0,10,10);
    liveIcon2->setPos(60,6);

    //create liveIcon3
    liveIcon3 = new liveIcon();
    liveIcon3->setRect(0,0,10,10);
    liveIcon3->setPos(75,6);


    //make it focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //add player to scene
    scene->addItem(player);

    //add liveIcon to scene
    scene->addItem(liveIcon1);
    scene->addItem(liveIcon2);
    scene->addItem(liveIcon3);

    //create score/health
    score1 = new score();
    scene->addItem(score1);
    health1 = new health();
    health1->setPos(health1->x(),health1->y()+25);
    scene->addItem(health1);



    //spawn enemies (zeitpunkt des timers(spanws)
   QTimer * timer = new QTimer();
   QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn())); //spawn greift auf create enemy zu
   timer->start(800);

/*   //für zweiten gegner
   QTimer * timer1 = new QTimer();
   QObject::connect(timer1,SIGNAL(timeout()),player,SLOT(spawn1()));
   timer1->start(5000);
*/
}
