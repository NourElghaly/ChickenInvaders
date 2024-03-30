#include "enemy.h"
#include "player.h"
#include "stdlib.h"
#include <QTimer>
#include "health.h"

enemy::enemy() : QObject(), QGraphicsPixmapItem()
{
    // Random position
    int random = rand() % 700;
    setPos(random, 0);
    // Timer
    QTimer *timer = new QTimer();
    // Image
    setPixmap(QPixmap(":/images/chicken.png").scaled(100, 100));

    // Connect
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void enemy::move()
{
     //Setting sound for when chicken collides with bullet
    QAudioOutput* coocoo=new QAudioOutput();
    QMediaPlayer*cooeffect=new QMediaPlayer();
    cooeffect->setSource(QUrl("qrc:/coocoo.mp3"));
    cooeffect->setAudioOutput(coocoo);
    coocoo->setVolume(50);


    // Movement
    setPos(x(), y() + 7);
    // Removing health and score when hitting enemy
    QList<QGraphicsItem *> collide = collidingItems();
    for (int i = 0, n = collide.size(); i < n; ++i)
    {
        if (typeid(*(collide[i])) == typeid(player))
        {
            health::decrease();
            cooeffect->play();
            scene()->removeItem(this);
            delete this;
            return;
        }
    }
    // Handling out of bounds
    if (pos().y() + boundingRect().height() > scene()->height() || pos().y() < 0)
    {
        health::decrease();
        scene()->removeItem(this);
        delete this;
    }
}

