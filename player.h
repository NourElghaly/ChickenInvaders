#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem> // Include for QGraphicsTextItem
#include <QTimer>

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player(QObject *parent = nullptr);

    void keyPressEvent(QKeyEvent *event) override;
    void up_score();
    void down_health();
    int get_health();

private:
    int player_health;
    int player_score;
    QGraphicsTextItem *health_text; // Text item for health
    QGraphicsTextItem *score_text;  // Text item for score
    QTimer *time;

private slots:
    void create_enemy();
};

#endif // PLAYER_H
