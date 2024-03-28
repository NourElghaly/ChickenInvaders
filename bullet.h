#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsScene>
#include <QMediaPlayer>

class Bullet : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Bullet();
   // QMediaPlayer*lose=new QMediaPlayer();    // Modified constructor
public slots:
    void move();
};

#endif // BULLET_H
