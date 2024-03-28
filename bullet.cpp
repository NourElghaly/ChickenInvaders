#include "bullet.h"
#include "enemy.h"
#include <QTimer>
#include <QList>
#include <QGraphicsScene>
#include "player.h"

Bullet::Bullet() {
    setPixmap(QPixmap(":/images/missle.png").scaled(30, 60));
    // Timer
    QTimer *timer = new QTimer(this); // Set parent to manage memory
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Bullet::move()
{
    // Colliding condition
    QList<QGraphicsItem *> collide = collidingItems();
    for(int i = 0, n = collide.size(); i < n; ++i)
    {
        if(typeid(*(collide[i])) == typeid(Enemy))
        {
            Enemy *enemy = dynamic_cast<Enemy *>(collide[i]);
            if (enemy)
            {
                Player *player = scene()->findChild<Player *>(); // Find player in scene
                if (player)
                    player->up_score();
            }
            scene()->removeItem(collide[i]); // Remove enemy from the scene
            scene()->removeItem(this); // Remove bullet from the scene
            delete collide[i]; // Delete enemy object
            delete this; // Delete bullet object
            return;
        }
    }

    setPos(x(), y() - 10);

    if(pos().y() + pixmap().height() < 0)
    {
        scene()->removeItem(this); // Remove bullet from the scene
        delete this; // Delete bullet object
    }
}
