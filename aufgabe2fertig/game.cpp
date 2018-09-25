#include "game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "button.h"
#include <QGraphicsRectItem>
#include "enemies.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QPalette>
#include <QBrush>



enemies *enemiess;

game::game(QWidget *parent)
{
    //set up the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    scene->setBackgroundBrush(Qt::darkGray);
    setScene(scene);

    //set up the screen
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    //create player to put into scene
    player = new myPlayer();
    player->setRect(0,0,100,20);
    player->setPos(350,500);
    player->setBrush(Qt::black);

    //create liveIcon1
    liveIcon1 = new liveIcon();
    liveIcon1->setRect(0,0,10,10);
    liveIcon1->setPos(45,6);
    liveIcon1->setBrush(Qt::red);

    //create liveIcon2
    liveIcon2 = new liveIcon();
    liveIcon2->setRect(0,0,10,10);
    liveIcon2->setPos(60,6);
    liveIcon2->setBrush(Qt::red);

    //create liveIcon3
    liveIcon3 = new liveIcon();
    liveIcon3->setRect(0,0,10,10);
    liveIcon3->setPos(75,6);
    liveIcon3->setBrush(Qt::red);

    //make it focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();


    //create score/health
    score1 = new score();
    health1 = new health();
  //  health1->setPos(health1->x(),health1->y()+25);
    health1->setPos(670,570);

}


void game::prestart()
{
    //create title text
    title = new QGraphicsTextItem(QString("C++ Aufgabe 2: SoSe 2017"));
    QFont titleFont("comic sans",50);
    title->setFont(titleFont);
    int txPos = this->width()/2 - title->boundingRect().width()/2;
    int tyPos = 100;
    title->setPos(txPos,tyPos);
    scene->addItem(title);


    //create play button for main menu
    startbuttonmain = new button1(QString("Play"));
    int bx1Pos = this->width()/2 - startbuttonmain->boundingRect().width()/2;
    int by1Pos = 200;
    startbuttonmain->setPos(bx1Pos,by1Pos);
    connect(startbuttonmain,SIGNAL(clicked()),SLOT(start()));
    scene->addItem(startbuttonmain);

    //create main menu quit button
    quitbuttonmain = new button1(QString("Quit"));
    int q1xPos = this->width()/2 - quitbuttonmain->boundingRect().width()/2;
    int q1yPos = 350;
    quitbuttonmain->setPos(q1xPos,q1yPos);
    connect(quitbuttonmain,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitbuttonmain);

    //create load button for main menu
    loadmain = new button1(QString("Load"));
    int lx1Pos = this->width()/2 - loadmain->boundingRect().width()/2;;
    int ly1Pos = 275;
    loadmain->setPos(lx1Pos,ly1Pos);
    connect(loadmain,SIGNAL(clicked()),this,SLOT(load()));
    scene->addItem(loadmain);

    //create pause button
    stopbutton = new button(QString("Pause"));
    int pxPos = 450;
    int pyPos = 10;
    stopbutton->setPos(pxPos,pyPos);
    connect(stopbutton,SIGNAL(clicked()),SLOT(stop()));

    //create Continue button
    resumebutton = new button(QString("Continue"));
    int rxPos = 370;
    int ryPos = 10;
    resumebutton->setPos(rxPos,ryPos);
    connect(resumebutton,SIGNAL(clicked()),SLOT(resume()));

    //create quit button
    quit= new button(QString("Quit"));
    int qxPos = 690;
    int qyPos = 10;
    quit->setPos(qxPos,qyPos);
    connect(quit,SIGNAL(clicked()),this,SLOT(close()));

    //create load button
    loadbutton = new button(QString("Load"));
    int lxPos = 610;
    int lyPos = 10;
    loadbutton->setPos(lxPos,lyPos);
    connect(loadbutton,SIGNAL(clicked()),this,SLOT(load()));

    //create save button
    savebutton = new button(QString("Save"));
    int sxPos = 530;
    int syPos = 10;
    savebutton->setPos(sxPos,syPos);
    connect(savebutton,SIGNAL(clicked()),this,SLOT(save()));

}

void game::start()
{
    //timer für spawn()
    timer = new QTimer();
      QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn())); //spawn greift auf create enemy zu
       timer->start(750);

    timer1 = new QTimer();
      QObject::connect(timer1,SIGNAL(timeout()),player,SLOT(spawn1())); //spawn greift auf create enemy zu
       timer1->start(1000);

    timer2 = new QTimer();
         QObject::connect(timer2,SIGNAL(timeout()),player,SLOT(spawn2())); //spawn greift auf create enemy zu
          timer2->start(20000);

//add resume button
              scene->addItem(resumebutton);
//add player to scene
       scene->addItem(player);
//add score to scene
       scene->addItem(health1);
//add liveIcon to scene
       scene->addItem(liveIcon1);
       scene->addItem(liveIcon2);
       scene->addItem(liveIcon3);
//Add live to Scene:
       scene->addItem(score1);
       scene->addItem(quit);
       scene->addItem(loadbutton);
       scene->addItem(savebutton);
       scene->addItem(stopbutton);
//Remove Main button buttons
       scene->removeItem(startbuttonmain);
       scene->removeItem(quitbuttonmain);
       scene->removeItem(loadmain);
//Remove title
       scene->removeItem(title);
}

void game::stop()
{
    //stop timer enemie"generator" aus start()
    timer->stop();
    timer1->stop();
    timer2->stop();
    player->hide();
}

void game::resume()
{
    //startet timer enemie "generator" erneut
    timer->start();
    timer1->start();
    timer2->start();
    player->show();
}
//diese funktionen sind wahrscheinlich überflüssig, da die notwendigen
//daten aus enemies.cpp bezogen werden!!!
void game::save()
{
    QFileDialog dialog(this);
    QString fileName;
    QFile file;

    dialog.setFileMode(QFileDialog::AnyFile);
    fileName = dialog.getSaveFileName(this,tr("Speichern als"),".",tr("Zeichnungen(*.myz)"));

    if(fileName.isNull()==false)
    {
        file.setFileName(fileName);
        if(!file.open(QIODevice::WriteOnly | QIODevice::Text ))
        {
            QMessageBox::warning(this,tr("Dateifehler"),tr("Folgende Datei kann nicht verwendet werdden: ") + fileName,QMessageBox::Ok);
        }


        file.close();
        return;
    }
}

void game::load()
{
    QFileDialog dialog(this);
    QString fileName;
    QFile file;

    dialog.setFileMode(QFileDialog::AnyFile);
    fileName = dialog.getOpenFileName(this, tr("Öffnen"),".",tr("Zeichnungen(*.myz)"));

    //if data can't get loaded
    if(fileName.isNull()==false)
    {
        file.setFileName(fileName);
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QMessageBox::warning(this,tr("Dateifehler"),tr("Folgende Datei kann nicht geladen werden: ")+ fileName,QMessageBox::Ok);
        }

        file.close();
        return;
    }
}



