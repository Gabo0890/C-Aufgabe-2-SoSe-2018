#include <QGraphicsTextItem>


class score : public QGraphicsTextItem{
public:
    score(QGraphicsItem * parent=0);
    void decreaseLive();
    int getScore();
private:
    int score1;
};
