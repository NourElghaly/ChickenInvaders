// bullet.h
#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet();
public slots:
    void move(); // Removed Player* parameter
};

#endif // BULLET_H
