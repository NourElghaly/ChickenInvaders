#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>
#include <QAudioOutput>

class Bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet();
    QMediaPlayer*bullet_sound=new QMediaPlayer();

public slots:
    void move();


private:

};

#endif // BULLET_H
