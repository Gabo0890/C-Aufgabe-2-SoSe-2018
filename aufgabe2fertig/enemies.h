#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>
#include <QFile>
#include <QWidget>
#include <vector>





class enemies: public QObject,public QGraphicsRectItem{
  Q_OBJECT
public:

    enemies();


    //public attributes
    QTimer * timer1;

    int lastX;
    int lastY;



public slots:
    void move();
    void stop();
    void resume();
    void save(QFile &file);
    void load(QFile &file);
};

class enemies1: public QObject,public QGraphicsEllipseItem{
  Q_OBJECT
public:

    enemies1();


    //public attributes
    QTimer * timer1;
    int lastX;
    int lastY;


public slots:
    void move();
    void stop();
    void resume();
    void save(QFile &file);
    void load(QFile &file);
};

class enemies2: public QObject,public QGraphicsRectItem{
  Q_OBJECT
public:

    enemies2();


    //public attributes
    QTimer * timer1;

    int lastX;
    int lastY;




public slots:
    void move();
    void stop();
    void resume();
    void save(QFile &file);
    void load(QFile &file);


};

class enemies3: public QObject,public QGraphicsRectItem{
  Q_OBJECT
public:

    enemies3();

    //public attributes
    QTimer * timer1;
    int lastX;
    int lastY;
    int increment;
    int phase;
    int phase1;


public slots:
    void move();
    void stop();
    void resume();
    void save(QFile &file);
    void load(QFile &file);
};


