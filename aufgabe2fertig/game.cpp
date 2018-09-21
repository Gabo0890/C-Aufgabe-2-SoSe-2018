#include "game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "enemies.h"

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


    //make it focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //add player to scene
    scene->addItem(player);

    //create score/health
    score1 = new score();
    scene->addItem(score1);
    health1 = new health();
    health1->setPos(health1->x(),health1->y()+25);
    scene->addItem(health1);



    //spawn enemies (zeitpunkt des timers(spanws)
   QTimer * timer = new QTimer();
   QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn())); //spawn greift auf create enemy zu
   timer->start(3500);

/*   //für zweiten gegner
   QTimer * timer1 = new QTimer();
   QObject::connect(timer1,SIGNAL(timeout()),player,SLOT(spawn1()));
   timer1->start(5000);
*/
}
