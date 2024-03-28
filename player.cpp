#include "player.h"
#include<QKeyEvent>
#include <QGraphicsScene>
#include "bullet.h"
#include "enemy.h"

player::player()
{
    // Bullet sounds
    QAudioOutput *mainBullet;
    mainBullet = new QAudioOutput();
    mainBullet->setVolume(20);
    bullet_sound->setAudioOutput(mainBullet);
    bullet_sound->setSource(QUrl("qrc:/audios/bullet_sound.mp3"));
    // Setting image
    setPixmap(QPixmap(":images/spaceship.png"));
}

void player::keyPressEvent(QKeyEvent *event)
{
    // Player movement
    if(event->key() == Qt::Key_Left)
    {
        if(pos().x() > 9)
            setPos(x() - 30, y());
    }
    else if(event->key() == Qt::Key_Right)
    {
        if(pos().x() + 70 < 800)
            setPos(x() + 30, y());
    }
    else if(event->key() == Qt::Key_Up)
    {
        if(pos().y() != 0)
            setPos(x(), y() - 20);
    }
    else if(event->key() == Qt::Key_Down)
    {
        if(pos().y() < 700)
            setPos(x(), y() + 20);
    }
    else if(event->key() == Qt::Key_Space)
    {
        // Bullet spawn
        bullet *bullet = new class bullet();
        bullet->setPos(x(), y());
        scene()->addItem(bullet);
        if(bullet_sound->isPlaying())
        {
            bullet_sound->setPosition(0);
        }
        else if(bullet_sound->isPlaying() == QMediaPlayer::StoppedState)
        {
            bullet_sound->play();
        }
    }
}

// Enemy creation
void player::spawn()
{
    enemy *enemy = new class enemy();
    scene()->addItem(enemy);
}
