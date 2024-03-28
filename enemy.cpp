#include "enemy.h"
#include <stdlib.h>
#include <QTimer>
#include <QList>
#include <QGraphicsScene>
#include "player.h"
#include "enemy.h"
#include "health.h"

Enemy::Enemy() : QObject(), QGraphicsPixmapItem() {
   setPixmap(QPixmap(":/images/chicken.png").scaled(100,100));

    int random_number = rand() % 700;
    setPos(random_number, 0);

    QTimer *timer =new QTimer();
    //connect
    connect(timer, SIGNAL(timeout()),this,SLOT (move()));
    timer->start(50);
}

void Enemy::move()
{

    //removing health when hitting enemy
    QList<QGraphicsItem *> collide=collidingItems();
    for(int i=0, n=collide.size();i<n;++i)
    {
        if(typeid(*(collide[i]))==typeid(Player))
        {
            health playerhealth;
            playerhealth.decrease();
            scene()->removeItem(this);
            delete this;
            return;
        }
    }

     //movment
    setPos(x(),y()+10);
    if(y()+pixmap().height()>600)
    {
        scene()->removeItem(this);
        delete this;
    }

}



