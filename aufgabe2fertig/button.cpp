#include "button.h"
#include <QGraphicsRectItem>
#include <QBrush>


button::button(QString name, QGraphicsItem *parent) : QGraphicsRectItem(parent)
{
    //draw rect
    setRect(0,0,80,18);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkRed);
    setBrush(brush);

    //draw text
    text = new QGraphicsTextItem(name,this);
    int xPos = rect().width()/2 - text->boundingRect().width()/2;
    int yPos = rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(xPos,yPos);

    //allow responding to hover events
    setAcceptHoverEvents(true);
}

void button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
}

void button::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    //change color
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    setBrush(brush);
}

void button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    //change color
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkRed);
    setBrush(brush);
}
