#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "player.h"
#include "score.h"
#include "health.h"
#include "liveicon.h"
#include <QFile>
#include <QTimer>
#include <QGraphicsRectItem>



class game : public QGraphicsView{
    Q_OBJECT

public:
   game(QWidget * parent=NULL);

    //public methods


        void prestart();




//public attributs
    QGraphicsScene * scene;
    myPlayer * player;
    score * score1;
    health * health1;
    liveIcon * liveIcon1;
    liveIcon * liveIcon2;
    liveIcon * liveIcon3;



public slots:
     void start();


};

