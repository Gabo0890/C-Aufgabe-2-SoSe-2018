#include "health.h"
#include <QFont>


health::health(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    //score bei 0 initialisieren
    health1 = 0;


    //text abbilden
    setPlainText(QString("score: ")+ QString::number(health1));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",15));
}

void health::increaseScore()
{
    health1++;

  //  for(health1 = 0; health1>=0; health1+=5){
    //for schleife für verschiedene scores (muss noch erweitert werden)

    setPlainText(QString("score: ")+ QString::number(health1)); //hinter score objekte laden, die die number ersetzen
}



int health::getHealth()
{
    return health1;
}
