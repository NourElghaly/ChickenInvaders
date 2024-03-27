#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsScene>

class Bullet : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Bullet(); // Modified constructor
public slots:
    void move();
private:
    QGraphicsPixmapItem*image2;
};

#endif // BULLET_H
