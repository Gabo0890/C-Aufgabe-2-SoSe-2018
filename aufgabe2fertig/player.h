#include <QGraphicsRectItem>
#include <QObject>

class myPlayer:public QObject, public QGraphicsRectItem {
    Q_OBJECT
  public:
    void keyPressEvent(QKeyEvent * event);


public slots:
    void spawn();
    void spawn1();
    void spawn2();
    void spawn3();



    //evtl noch spawn1(), spawn2() implementieren um einfacher enemies zu kategorisieren
};
