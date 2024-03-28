#include "player.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "enemy.h"
#include <QTimer>
#include "bullet.h"

Player::Player()
{
    time = new QTimer();
    QObject::connect(time, SIGNAL(timeout()),this,SLOT(create_enemy()));
    time->start(2000);
}

void Player::keyPressEvent(QKeyEvent *event) // Corrected function name
{
    if(event->key()== Qt::Key_Left)
    {
        if(x()>0)
        {
            setPos(x()-40,y());
        }
    }
    else if(event->key()== Qt::Key_Right)
    {
        if(x()+100<800)
            setPos(x()+40,y());
    }
    else if(event->key()== Qt::Key_Up)
    {
        if(y()>0)
            setPos(x(),y()-40);
    }
    else if(event->key()== Qt::Key_Down)
    {
        if(y()+100<800)
            setPos(x(),y()+40);
    }
    else if(event->key()== Qt::Key_Space)
    {
        Bullet * bullet = new Bullet();
        bullet->setPos(x()+25,y()-65);
        scene()->addItem(bullet);
    }
}

void Player::create_enemy()
{
    Enemy* enemy = new Enemy();
    scene()->addItem(enemy);
}
