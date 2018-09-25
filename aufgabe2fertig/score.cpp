//#include "score.h"
#include <QFont>
#include "game.h"



extern game * gamee;



score::score(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    //score bei 0 initialisieren
    score1 = 3;

    //text abbilden
    setPlainText(QString("Lives: "));//+ QString::number(score1)); //letzter teil zeigt wert von score1 an
    setDefaultTextColor(Qt::darkRed);                                // nicht notwendig, da objekte gesetzt werdden
    setFont(QFont("times",15));

   /* //connect
    timer2 = new QTimer(this);
    connect(timer2,SIGNAL(timeout()),this,SLOT(decreaseLive()));
    timer2->start(); */
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
        //  enemiess->timer1->stop();


    }
  //  setPlainText(QString("Lives: ")+ QString::number(score1)); //hinter score objekte laden, die die number ersetzen


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

    //Timer wird gestoppt
   // timer2->stop();
  //  enemiess->timer1->stop();
}
