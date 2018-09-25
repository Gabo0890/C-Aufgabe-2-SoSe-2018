#include <QGraphicsTextItem>
#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>


class score : public QGraphicsTextItem{
   // Q_OBJECT
public:
    score(QGraphicsItem * parent=0);

    int getScore();

    //public aattributes
    QTimer * timer2;
    int score1;

public slots:
    void stop();
    void decreaseLive();
    void increaselive();
signals:
   // void anhalten();
};


