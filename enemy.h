#ifndef ENEMY_H
#define ENEMY_H
#include <QObject>
#include <QGraphicsPixmapItem>

class Enemy: public QObject , public QGraphicsRectItem
{
    Q_OBJECT
public:
    Enemy();
public slots:
    void move();
private:
    QGraphicsPixmapItem * image3;
};


#endif // ENEMY_H
