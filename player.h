#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QKeyEvent>
#include <QMediaPlayer>


class Player : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Player();
    void keyPressEvent(QKeyEvent *event);
    QMediaPlayer *bulletaudio=new QMediaPlayer();
private:
    QTimer*time;

public slots:
    void create_enemy();
};

#endif // PLAYER_H
