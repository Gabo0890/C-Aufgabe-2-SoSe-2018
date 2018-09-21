#include <QGraphicsRectItem>
#include <QObject>


class enemies: public QObject,public QGraphicsRectItem{
  Q_OBJECT
public:
    enemies();
  //  enemies1();
  // enemies2();
public slots:
    void move();
};

//idee: weitere klassen für andere gegner kategorien implementieren
