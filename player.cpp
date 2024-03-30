#include "player.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "bullet.h"
#include "enemy.h"

player::player()
{
    // Setting image
    setPixmap(QPixmap(":/images/spaceship.png").scaled(100, 100));

}


void player::keyPressEvent(QKeyEvent *event)
{

    QAudioOutput* missle=new QAudioOutput();
    QMediaPlayer*missleeffect=new QMediaPlayer();
    missleeffect->setSource(QUrl("qrc:/missle_sound.mp3"));
    missleeffect->setAudioOutput(missle);
    missle->setVolume(50);

    // Player movement
    if (event->key() == Qt::Key_Left)
    {
        if (pos().x() - 30 >= 0) // Check if moving left would keep the player within scene boundaries
            setPos(x() - 30, y());
        else
            setPos(0, y()); // If not, set the player's position to the leftmost edge of the scene
    }
    else if (event->key() == Qt::Key_Right)
    {
        if (pos().x() + 30 <= scene()->width() - pixmap().width()) // Check if moving right would keep the player within scene boundaries
            setPos(x() + 30, y());
        else
            setPos(scene()->width() - pixmap().width(), y()); // If not, set the player's position to the rightmost edge of the scene
    }
    else if (event->key() == Qt::Key_Up)
    {
        if (pos().y() - 20 >= 0) // Check if moving up would keep the player within scene boundaries
            setPos(x(), y() - 20);
        else
            setPos(x(), 0); // If not, set the player's position to the top edge of the scene
    }
    else if (event->key() == Qt::Key_Down)
    {
        if (pos().y() + 20 <= scene()->height() - pixmap().height()) // Check if moving down would keep the player within scene boundaries
            setPos(x(), y() + 20);
        else
            setPos(x(), scene()->height() - pixmap().height()); // If not, set the player's position to the bottom edge of the scene
    }
    else if (event->key() == Qt::Key_Space)
    {
        // Bullet appearing
        Bullet *bullet = new Bullet;
        bullet->setPos(x() + pixmap().width() / 2 - bullet->pixmap().width() / 2, y());
        scene()->addItem(bullet);

        if(missleeffect->isPlaying())
        {
            missleeffect->setPosition(0);
        }
        else if(missleeffect->isPlaying()==QMediaPlayer::StoppedState)
        {
            missleeffect->play();
        }
    }
}

// Enemy creation
void player::generate()
{
    enemy *enemy = new class enemy();
    scene()->addItem(enemy);
}
