#include "bolita.h"

bolita::bolita()
{
    vy=7;
}

QRectF bolita::boundingRect() const
{
    return QRectF(-10,-10,7,7);
}

void bolita::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->setBrush(Qt::darkBlue);
    //painter->drawEllipse(boundingRect());
    QPixmap pixmap;
    pixmap.load(":/Imagenes/pokebola.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

void bolita::mover()
{
    setPos(x(),y());
}

void bolita::choque()
{
    vy=-vy/1.3;
}
