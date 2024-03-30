#ifndef PLAYER_H
#define PLAYER_H

#include <QMediaPlayer>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QAudioOutput>

class player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    player();
    void keyPressEvent(QKeyEvent *event);


public slots:
    void generate();
};

#endif // PLAYER_H
