#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QKeyEvent>

class Player : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Player(QGraphicsTextItem *score = nullptr);
    void keyPressEvent(QKeyEvent *event) override;
    void createEnemy();
private:
    int scoreValue;
    QGraphicsTextItem *score;
};

#endif // PLAYER_H
