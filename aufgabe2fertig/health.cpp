#include "health.h"
#include <QFont>


health::health(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    //score bei 0 initialisieren
    health1 = 0;


    //text abbilden
    setPlainText(QString("Score: ")+ QString::number(health1));
    setDefaultTextColor(Qt::darkRed);
    setFont(QFont("times",20));

}

void health::increaseScore()
{
    health1++;

  //  for(health1 = 0; health1>=0; health1+=5){
    //for schleife für verschiedene scores (muss noch erweitert werden)

    setPlainText(QString("Score: ")+ QString::number(health1)); //hinter score objekte laden, die die number ersetzen
}



int health::getHealth()
{
    return health1;
}
