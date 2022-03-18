#ifndef BOLITA_H
#define BOLITA_H


#include <QGraphicsItem>
#include <QPainter>

class bolita : public QGraphicsItem
{
public:
    bolita();
    QRectF boundingRect() const;
    void paint(QPainter *painter,
       const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mover();
    void choque();
    int vy;
};

#endif // BOLITA_H
