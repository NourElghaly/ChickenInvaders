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
    // Losing score sound
    QAudioOutput *mainlosing;
    mainlosing = new QAudioOutput();
    mainlosing->setVolume(10);
    //lose->setAudioOutput(mainlosing);
   // lose->setSource(QUrl("qrc:/audios/mixkit-losing-bleeps-2026.mp3"));
    // Connect
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void enemy::move()
{
    // Movement
    setPos(x(), y() + 7);
    // Removing health and score when hitting enemy
    QList<QGraphicsItem *> collide = collidingItems();
    for (int i = 0, n = collide.size(); i < n; ++i)
    {
        if (typeid(*(collide[i])) == typeid(player))
        {
          //  if (lose->isPlaying())
            {
           //     lose->setPosition(0);
            }
           // else if (lose->isPlaying() == QMediaPlayer::StoppedState)
            {
           //     lose->play();
            }
            health::decrease();
            scene()->removeItem(this);
            delete this;
            return;
        }
    }
    // Handling out of bounds
    if (pos().y() + boundingRect().height() > scene()->height() || pos().y() < 0)
    {
       // if (lose->isPlaying())
        {
       //     lose->setPosition(0);
        }
      //  else if (lose->isPlaying() == QMediaPlayer::StoppedState)
        {
       //     lose->play();
        }
        health::decrease();
        scene()->removeItem(this);
        delete this;
    }
}

