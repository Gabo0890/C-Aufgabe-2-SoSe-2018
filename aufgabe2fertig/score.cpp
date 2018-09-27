#include <QFont>
#include "game.h"
#include <QTime>
#include <QCoreApplication>




extern game * gamee;




score::score(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    //score bei 0 initialisieren
    score1 = 3;

    //text abbilden
    setPlainText(QString("Lives: "));//+ QString::number(score1)); //letzter teil zeigt wert von score1 an
    setDefaultTextColor(Qt::darkRed);                                // nicht notwendig, da objekte gesetzt werdden
    setFont(QFont("times",15));

}

void score::decreaseLive()
{
    score1--;


    if(score1==2){
    gamee->liveIcon3->setBrush(Qt::darkGray);
    //gamee->player->setRect(0,0,120,25);
    gamee->player->setOpacity(0.6);



    }

    if(score1==1){
        gamee->liveIcon2->setBrush(Qt::darkGray);
        gamee->player->setOpacity(0.3);
    }
    if(score1==0){
        gamee->liveIcon1->setBrush(Qt::darkGray);
        gamee->player->hide();

        //connect(enemiess->timer1,SIGNAL(timeout()),SLOT(stop()));
        gamee->timer->stop();
        gamee->timer1->stop();
        gamee->timer2->stop();
        gamee->timer3->stop();

        //load game menu after death
        //Problem: soll werte von live und score resetten
        gamee->scene->addItem(gamee->startbuttonmain);
        gamee->scene->addItem(gamee->quitbuttonmain);
        gamee->scene->addItem(gamee->loadmain);
        //Remove Gamebuttons
        gamee->scene->removeItem(gamee->resumebutton);
        gamee->scene->removeItem(gamee->loadbutton);
        gamee->scene->removeItem(gamee->savebutton);
        gamee->scene->removeItem(gamee->stopbutton);
        gamee->scene->removeItem(gamee->quit);
        gamee->scene->removeItem(gamee->liveIcon1);
        gamee->scene->removeItem(gamee->liveIcon2);
        gamee->scene->removeItem(gamee->liveIcon3);
        gamee->scene->removeItem(gamee->score1);
        //set Score and Game over text
        gamee->health1->setPos(275,100);
        gamee->health1->setScale(3);
        gamee->scene->addItem(gamee->gameover);

    }


}

void score::increaselive()
{
    score1++;
       if(score1==3){
           gamee->liveIcon3->setBrush(Qt::red);
           gamee->player->setOpacity(1);
       }
       if(score1==2){
           gamee->liveIcon2->setBrush(Qt::red);
           gamee->player->setOpacity(0.6);
       }

}

int score::getScore()
{
    return score1;
}

void score::stop()
{


}
