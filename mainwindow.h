#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsLineItem>
#include <QKeyEvent>
#include <QPainter>
#include <QTimer>
#include "miesfera.h"
#include "bolita.h"
#include <iostream>
#include <vector>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void aviso(int);

public slots:
    void animar();
    void aumentarPunt();

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    QGraphicsRectItem* barra;
    QGraphicsRectItem* barra2;
    QGraphicsRectItem* barra3;
    QGraphicsRectItem* barra4;
    QGraphicsRectItem* barra5;
    QGraphicsRectItem* barra6;
    QGraphicsLineItem* l1;
    QGraphicsLineItem* l2;
    QGraphicsLineItem* l3;
    QGraphicsLineItem* l4;
    miesfera* bola;
    bolita* bolita1;
    bolita* bolita2;
    bolita* bolita3;
    bolita* bolita4;
    bolita* bolita5;
    bolita* bolita6;
    bolita* bolita7;
    bolita* bolita8;
    bolita* bolita9;
    bolita* bolita10;
    bolita* bolita11;
    QTimer *timer;

    int puntuacion;

    bool moverIx1;
    bool moverDx1;
    bool moverUy1;
    bool moverDy1;
    bool mover2;

    void keyPressEvent(QKeyEvent *ev);
    void keyReleaseEvent(QKeyEvent *ev);
    //void mousePressEvent(QMouseEvent *ev);
};
#endif // MAINWINDOW_H
