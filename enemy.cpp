#include "enemy.h"
#include <stdlib.h>
#include <QTimer>
#include <QList>
#include <QGraphicsScene>
#include "player.h"
#include "enemy.h"

Enemy::Enemy() : QObject(), QGraphicsPixmapItem() {
   setPixmap(QPixmap(":/images/chicken.jpg").scaled(100,100));

    int random_number = rand() % 700;
    setPos(random_number, 0);

    QTimer *timer =new QTimer();
    //connect
    connect(timer, SIGNAL(timeout()),this,SLOT (move()));
    timer->start(50);
}

void Enemy::move()
{



    //removing health and score when hitting enemy
    QList<QGraphicsItem *> collide=collidingItems();
    for(int i=0, n=collide.size();i<n;++i)
    {
        if(typeid(*(collide[i]))==typeid(Player))
        {
            //if(lose->isPlaying())
            {
               // lose->setPosition(0);
            }
            //else if(lose->isPlaying()==QMediaPlayer::StoppedState)
            {
              //  lose->play();
            }
           // health::decrease();
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



