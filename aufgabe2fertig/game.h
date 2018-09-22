#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "player.h"
#include "score.h"
#include "health.h"
#include "liveicon.h"

class game : public QGraphicsView{
public:
    game(QWidget * parent=0);

    QGraphicsScene * scene;
    myPlayer * player;
    score * score1;
    health * health1;
    liveIcon * liveIcon1;
    liveIcon * liveIcon2;
    liveIcon * liveIcon3;


};
