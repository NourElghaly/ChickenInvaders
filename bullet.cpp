#include "bullet.h"
#include "enemy.h"
#include <QTimer>
#include <QList>
#include <score.h>
#include <QGraphicsPixmapItem>
#include <QPixmap>

Bullet::Bullet() {
    setPixmap(QPixmap(":/images/missle.png").scaled(30,60));
        //timer
    QTimer *timer =new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT (move()));
    timer->start(50);
}



void Bullet::move()
{
    //colliding condition
    QList<QGraphicsItem *> collide=collidingItems();
    for(int i=0, n=collide.size();i<n;++i)
    {
        if(typeid(*(collide[i]))==typeid(Enemy))
        {
            score::increase();
            scene()->removeItem(collide[i]);
            scene()->removeItem(this);
            delete collide[i];
            delete this;
            return;
        }
    }

    setPos(x(),y()-10);

    if(pos().y()+30<0)
    {
        scene()->removeItem(this);
        delete this;
    }

}


