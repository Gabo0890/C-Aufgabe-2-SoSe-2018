#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "player.h"
#include "score.h"
#include "health.h"

class game : public QGraphicsView{
public:
    game(QWidget * parent=0);

    QGraphicsScene * scene;
    myPlayer * player;
    score * score1;
    health * health1;


};
