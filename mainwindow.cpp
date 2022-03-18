#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <vector>
#include <QVector>
#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene=new QGraphicsScene(0,0,500,400);
    ui->graphicsView->setScene(scene);


    puntuacion = 0;
    moverIx1=false;
    moverDx1=false;
    moverUy1=false;
    moverDy1=false;
    mover2=false;

    //ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/fondo")));

    timer=new QTimer();

    connect(timer,SIGNAL(timeout()),this,SLOT(animar()));
    connect(this,SIGNAL(aviso(int)),this,SLOT(aumentarPunt()));

    timer->start(33);

    barra=new QGraphicsRectItem(-30,-10,150,25);
    scene->addItem(barra);
    barra->setPos(190,240);
 /*
    barra2=new QGraphicsRectItem(-30,-10,150,25);
    scene->addItem(barra2);
    barra2->setPos(190,150);

    barra3=new QGraphicsRectItem(-30,-10,25,80);
    scene->addItem(barra3);
    barra3->setPos(250,330);

    barra4=new QGraphicsRectItem(-30,-10,25,80);
    scene->addItem(barra4);
    barra4->setPos(250,11);
    */
    barra5=new QGraphicsRectItem(-30,-10,25,300);
    scene->addItem(barra5);
    barra5->setPos(412,50);

    barra6=new QGraphicsRectItem(-30,-10,25,300);
    scene->addItem(barra6);
    barra6->setPos(100,50);

    l1=new QGraphicsLineItem(0,0,500,0);
    l2=new QGraphicsLineItem(0,0,0,400);
    l3=new QGraphicsLineItem(500,0,500,400);
    l4=new QGraphicsLineItem(0,400,500,400);
    scene->addItem(l1);
    scene->addItem(l2);
    scene->addItem(l3);
    scene->addItem(l4);

    bola = new miesfera();

    scene->addItem(bola);
    bola->setPos(200,50);

    bolita1 = new bolita();
    scene->addItem(bolita1);
    bolita1->setPos(220,350);

    bolita2 = new bolita();
    scene->addItem(bolita2);
    bolita2->setPos(227,350);

    bolita3 = new bolita();
    scene->addItem(bolita3);
    bolita3->setPos(234,350);

    bolita4 = new bolita();
    scene->addItem(bolita4);
    bolita4->setPos(241,350);

    bolita5 = new bolita();
    scene->addItem(bolita5);
    bolita5->setPos(248,350);

    //scene->destroyed()


}

MainWindow::~MainWindow()
{
    delete scene;
    delete ui;
}


void MainWindow::animar()
{
    if(moverIx1 && bola->x()>20 && moverUy1!=true && moverDy1!=true && moverDx1!=true)
    {
        if(bola->x()>60 && bola->x()<125 && bola->y()>50&& bola->y()<350){
            bola->setPos(125,bola->y());
        }
        if(bola->x()>420 && bola->x()<445 && bola->y()>50&& bola->y()<350){
            bola->setPos(445,bola->y());
        }
        if(bola->x()>190 && bola->x()<340 && bola->y()>210&& bola->y()<265){
            bola->setPos(340,bola->y());
        }
        else{
        bola->setPos(bola->x()-2,bola->y());
        }

    }
    if(moverDx1 && bola->x()<480 && moverUy1!=true && moverDy1!=true &&moverIx1 !=true)
    {
        if(bola->x()>55 && bola->x()<125 && bola->y()>50&& bola->y()<350){
            bola->setPos(50,bola->y());
        }
        if(bola->x()>360 && bola->x()<445 && bola->y()>50&& bola->y()<350){
            bola->setPos(360,bola->y());
        }
        if(bola->x()>190 && bola->x()<340 && bola->y()>210&& bola->y()<265){
            bola->setPos(190,bola->y());
        }
        else{
            bola->setPos(bola->x()+2,bola->y());
        }
    }
    if(moverUy1 && bola->y()>20 && moverIx1!=true && moverDx1!=true && moverDy1 !=true)
    {
        if(bola->x()>55 && bola->x()<125 && bola->y()>50&& bola->y()<350){
            bola->setPos(bola->x(),350);
        }
        if(bola->x()>360 && bola->x()<445 && bola->y()>50&& bola->y()<350){
           bola->setPos(bola->x(),350);
        }
        if(bola->x()>190 && bola->x()<340 && bola->y()>210&& bola->y()<265){
             bola->setPos(bola->x(),265);
        }
        else{
            bola->setPos(bola->x(),bola->y()-2);
        }


   }

    if(moverDy1 && bola->y()<380 && moverIx1!=true && moverDx1!=true && moverUy1 !=true)
    {

        if(bola->x()>55 && bola->x()<125 && bola->y()>50&& bola->y()<350){
            bola->setPos(bola->x(),50);
        }
        if(bola->x()>360 && bola->x()<445 && bola->y()>50&& bola->y()<350){
           bola->setPos(bola->x(),50);
        }
        if(bola->x()>190 && bola->x()<340 && bola->y()>210&& bola->y()<265){
             bola->setPos(bola->x(),210);
        }
        else{
            bola->setPos(bola->x(),bola->y()+2);
        }


    }



    if(bola->collidesWithItem(bolita1)||bola->collidesWithItem(bolita2)||bola->collidesWithItem(bolita3) || bola->collidesWithItem(bolita4) ||bola->collidesWithItem(bolita5))
    {
        if(bolita1->isVisible()){
            bolita1->hide();
            emit aviso(9);
            //delete bola;
        }
        if(bolita2->isVisible()){
            bolita2->hide();
            emit aviso(9);
            //delete bola;
        }
        if(bolita3->isVisible()){
            bolita3->hide();
            emit aviso(9);
            //delete bola;
        }
        if(bolita4->isVisible()){
            bolita4->hide();
            emit aviso(9);
            //delete bola;
        }
        if(bolita5->isVisible()){
            bolita5->hide();
            emit aviso(9);
            //delete bola;
        }





    }

    /*for(int i=0; i<bolas.length();i++)
    {
        bolas.at(i)->mover();
        if(!bolas.at(i)->collidingItems().empty())
        {
            bolas.at(i)->choque();
        }
    }*/
}

void MainWindow::keyPressEvent(QKeyEvent *ev)
{
    if(ev->key()==Qt::Key_A)
    {
        moverIx1=true;
    }
    else if(ev->key()==Qt::Key_D)
    {
        moverDx1=true;
    }
    else if(ev->key()==Qt::Key_S)
    {
        moverUy1=true;
    }
    else if(ev->key()==Qt::Key_Z)
    {
        moverDy1=true;
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *ev)
{
    if(ev->key()==Qt::Key_A)
    {
        moverIx1=false;
    }
    else if(ev->key()==Qt::Key_D)
    {
        moverDx1=false;
    }
    else if(ev->key()==Qt::Key_S)
    {
        moverUy1=false;
    }
    else if(ev->key()==Qt::Key_Z)
    {
        moverDy1=false;
    }

}

void MainWindow::aumentarPunt()
{
    puntuacion += 5;
    ui->lcdNumber->display(puntuacion);
    std::cout<<puntuacion<<std::endl;
}




