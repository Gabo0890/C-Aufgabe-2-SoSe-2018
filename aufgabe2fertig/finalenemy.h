#ifndef FINALENEMY_H
#define FINALENEMY_H
#include <QWidget>
#include <QTimer>
#include <QFile>
#include <QObject>

class finalenemies: public QWidget{
    Q_OBJECT
public:
    finalenemies();

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


#endif // FINALENEMY_H
