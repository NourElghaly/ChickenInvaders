#include "bullet.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QList>
#include "enemy.h"
#include "points.h"

Bullet::Bullet()
{
    // Image
    setPixmap(QPixmap(":/images/missle.png").scaled(30, 60));
    // Timer
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Bullet::move()
{
    QAudioOutput* coocoo=new QAudioOutput();
    QMediaPlayer*cooeffect=new QMediaPlayer();
    cooeffect->setSource(QUrl("qrc:/coocoo.mp3"));
    cooeffect->setAudioOutput(coocoo);
    coocoo->setVolume(20);


    // Colliding condition
    QList<QGraphicsItem *> collide = collidingItems();
    for (int i = 0, n = collide.size(); i < n; ++i)
    {
        if (typeid(*(collide[i])) == typeid(enemy))
        {
            Points::increase();
            scene()->removeItem(collide[i]);
            scene()->removeItem(this);
            cooeffect->play();
            delete collide[i];
            delete this;
            return;
        }
    }
    // Movement
    setPos(x(), y() - 10);

    if (pos().y() + 30 < 0)
    {
        scene()->removeItem(this);
        delete this;
    }
}
