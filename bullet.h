#ifndef BULLET_H
#define BULLET_H

#include <QMediaPlayer>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QAudioOutput>

class bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    bullet();
    QMediaPlayer *enemy_sound = new QMediaPlayer();

public slots:
    void move();
};

#endif // BULLET_H
