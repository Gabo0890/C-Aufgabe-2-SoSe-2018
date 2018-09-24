#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>



class enemies: public QObject,public QGraphicsRectItem{
  Q_OBJECT
public:

    enemies();
    //public attributes
    QTimer * timer1;

public slots:
    void move();
    void stop();
    void resume();
};

//idee: weitere klassen für andere gegner kategorien implementieren
