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

void Player::keyPressEvent(QKeyEvent *event)
{
    // player movement
    if (event->key() == Qt::Key_Left)
    {
        if (pos().x() > 9)
            setPos(x() - 30, y());
    }
    else if (event->key() == Qt::Key_Right)
    {
        if (pos().x() + 70 < 800)
            setPos(x() + 30, y());
    }
    else if (event->key() == Qt::Key_Up)
    {
        if (pos().y() != 0)
            setPos(x(), y() - 20);
    }
    else if (event->key() == Qt::Key_Down)
    {
        // Ensure player doesn't go below the screen
        if (pos().y() + 20 < 600) // Check against the height of the view
            setPos(x(), y() + 20);
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
