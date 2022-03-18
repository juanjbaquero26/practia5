#include "miesfera.h"

miesfera::miesfera()
{
    vy=7;
}

QRectF miesfera::boundingRect() const
{
    return QRectF(-10,-10,25,25);
}

void miesfera::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->setBrush(Qt::darkBlue);
    //painter->drawEllipse(boundingRect());
    QPixmap pixmap;
    pixmap.load(":/Imagenes/pacman.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

void miesfera::mover()
{
    setPos(x(),y());
}

void miesfera::choque()
{
    vy=-vy/1.3;
}
