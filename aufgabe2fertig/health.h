#include <QGraphicsTextItem>


class health : public QGraphicsTextItem{
public:
    health(QGraphicsItem * parent=0);
    void increaseScore();
    int getHealth();
private:
    int health1;


};
