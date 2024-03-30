#include "bullet.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QList>
#include "enemy.h"
#include "points.h"

bullet::bullet()
{
    // Enemy sound
    QAudioOutput *soundEnemy;
    soundEnemy = new QAudioOutput();
    soundEnemy->setVolume(200);
    enemy_sound->setAudioOutput(soundEnemy);
    enemy_sound->setSource(QUrl("qrc:/audios/enemy_sound.mp3"));
    // Image
    setPixmap(QPixmap(":/images/missle.png").scaled(30, 60));
    // Timer
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void bullet::move()
{


    // Colliding condition
    QList<QGraphicsItem *> collide = collidingItems();
    for (int i = 0, n = collide.size(); i < n; ++i)
    {
        if (typeid(*(collide[i])) == typeid(enemy))
        {
            if (enemy_sound->isPlaying())
            {
                enemy_sound->setPosition(0);
            }
            else if (enemy_sound->isPlaying() == QMediaPlayer::StoppedState)
            {
                enemy_sound->play();
            }
            Points::increase();
            scene()->removeItem(collide[i]);
            scene()->removeItem(this);
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
