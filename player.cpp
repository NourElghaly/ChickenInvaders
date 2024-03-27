#include "player.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <enemy.h>
#include <bullet.h>

Player::Player(QGraphicsTextItem *score) : scoreValue(0), score(score) {

}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left)
    {
        if(x() > 0)
        {
            setPos(x() - 20, y());
        }
    }
    else if(event->key() == Qt::Key_Right)
    {
        if(x() + 100 < 800)
            setPos(x() + 20, y());
    }
    else if(event->key() == Qt::Key_Space)
    {
        Bullet *bullet = new Bullet(scene(), x(), y());
        scene()->addItem(bullet);
    }
}


void Player::createEnemy()
{
    Enemy* enemy = new Enemy();
    scene()->addItem(enemy);
}
