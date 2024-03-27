#include "bullet.h"
#include "enemy.h"
#include <QTimer>
#include <QList>
#include <QGraphicsPixmapItem>

Bullet::Bullet() {
    setPixmap(QPixmap(":/missles.png").scaled(30,60));
        //timer
    QTimer *timer =new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT (move()));
    timer->start(50);
}


void Bullet::move() {
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for (int i = 0; i < colliding_items.size(); ++i) {
        if (colliding_items[i] && typeid(*colliding_items[i]) == typeid(Enemy)) {
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    setPos(x(), y() - 10);
    if (pos().y() + pixmap().height() < 0) {
        scene()->removeItem(this);
        delete this;
    }
}

