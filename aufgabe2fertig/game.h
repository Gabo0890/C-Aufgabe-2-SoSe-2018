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
#include <QGraphicsTextItem>




class game : public QGraphicsView{
    Q_OBJECT

public:
   game(QWidget * parent=NULL);

    //public methods


        void prestart();




//public attributs
    QGraphicsScene * scene;
    QGraphicsTextItem * title;
    myPlayer * player;
    score * score1;
    health * health1;
    liveIcon * liveIcon1;
    liveIcon * liveIcon2;
    liveIcon * liveIcon3;
    QTimer * timer;
    QTimer *timer1;
    QTimer *timer2;
    button * startbutton;
    button1 * startbuttonmain;
    button1 * quitbuttonmain;
    button1 * loadmain;
    button * stopbutton;
    button *resumebutton;
    button * loadbutton;
    button * savebutton;
    button * quit;





public slots:
     void start();
     void stop();
     void resume();
     void load();
     void save();


};

