#include "enemy.h"
#include <stdlib.h>
#include <QTimer>
#include <QList>
#include <QGraphicsScene>
#include "player.h"

Enemy::Enemy() : QObject(), QGraphicsPixmapItem() {
    setPixmap(QPixmap(":/images/chicken.png").scaled(100, 100));

    int random_number = rand() % 700;
    setPos(random_number, 0);

    QTimer *timer = new QTimer(this); // Set parent to manage memory
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Enemy::move()
{
    // Removing health when hitting enemy
    QList<QGraphicsItem *> collide = collidingItems();
    for (int i = 0; i < collide.size(); i++) {
        if (typeid(*(collide[i])) == typeid(Player)) {
            // Remove both the enemy and the player
            Player *player = dynamic_cast<Player*>(collide[i]);
            if (player) {
                player->down_health(); // Call the decrease function of the player
                if (player->get_health()<= 0) { // Check if player's health is 0 or less
                    scene()->removeItem(collide[i]); // Remove the player from the scene
                    delete collide[i];
                }

                delete this;
                return;
            }
        }
    }

    // Movement
    setPos(x(), y() + 10);
    if(y() + pixmap().height() > 600)
    {
        scene()->removeItem(this); // Remove enemy from the scene
        delete this; // Delete enemy object
    }
}
