#include "score.h"
#include <QFont>


score::score(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    //score bei 0 initialisieren
    score1 = 3;

    //text abbilden
    setPlainText(QString("Lives: ")+ QString::number(score1));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",15));
}

void score::decreaseLive()
{
    score1--;
    setPlainText(QString("Lives: ")+ QString::number(score1)); //hinter score objekte laden, die die number ersetzen


}

int score::getScore()
{
    return score1;
}
