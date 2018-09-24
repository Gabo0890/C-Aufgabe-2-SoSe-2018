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
//#include "enemies.h"
#include "button.h"



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
    QTimer * timer;
    button * startbutton;
    button * stopbutton;
    button *resumebutton;





public slots:
     void start();
     void stop();
     void resume();


};

