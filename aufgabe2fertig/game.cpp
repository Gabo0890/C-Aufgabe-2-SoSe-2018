#include "game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "enemies.h"
#include "button.h"
//#include "liveicon.h"


game::game(QWidget *parent)
{
    //set up the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
   // setPalette(QPalette(QColor(125,125,125)));
    setScene(scene);

    //set up the screen
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
    QObject::connect(timer,SIGNAL(timeout()),SLOT(start())); //spawn greift auf create enemy zu
    timer->start(2200);

}



void game::prestart()
{
   /* //create title text
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Roadtrip through Asteroids"));
    QFont titleFont("comic sans",25);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);
*/
    //create play button
    button* playButton = new button(QString("Play"));
    int bxPos = 450;
    int byPos = 10;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playButton);

    //create quit button
    button* quitButton = new button(QString("Quit"));
    int qxPos = 530;
    int qyPos = 10;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitButton);

    //funktionen noch definieren!!!

    //create load button
    button* loadButton = new button(QString("Load"));
    int lxPos = 690;
    int lyPos = 10;
    loadButton->setPos(lxPos,lyPos);
    connect(loadButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(loadButton);

    //create save button
    button* saveButton = new button(QString("Save"));
    int sxPos = 610;
    int syPos = 10;
    saveButton->setPos(sxPos,syPos);
    connect(saveButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(saveButton);

}

void game::start()
{

    enemies * enemy1 = new enemies();
    scene->addItem(enemy1);


}






