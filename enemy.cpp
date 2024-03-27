#include "enemy.h"
#include <stdlib.h>
#include <QTimer>
#include <QList>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <player.h>

Enemy::Enemy() : QObject(), QGraphicsPixmapItem() {
    QPixmap enemypix(":/images/chicken.jpg");
    enemypix = enemypix.scaledToWidth(100);
    enemypix = enemypix.scaledToHeight(100);

    image3->setPixmap(enemypix);
    scene()->addItem(image3);

    int random_number = rand() % 700;
    setPos(random_number, 0);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Enemy::move() {
    // Move the enemy downwards
    setPos(x(), y() + 5);

    // Check if the enemy is out of bounds
    if (y() > scene()->height()) {
        scene()->removeItem(this);
        delete this;
    }
}



   // QList<QGraphicsItem*> colliding_items = collidingItems();
  //  for (int i = 0; i < colliding_items.size(); ++i) {
  //      if (typeid(*colliding_items[i]) == typeid(Player)) {
  //          scene()->removeItem(colliding_items[i]);
   //         scene()->removeItem(this);
     //       delete colliding_items[i];
         //   delete this;
          //  return;
        //}
   // }
//}
