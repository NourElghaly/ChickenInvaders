#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>
#include <QGraphicsItem>
#include <QGraphicsScene>

class health
{
public:
    health(QGraphicsScene *scene);
    static void decrease();

private:
    static int player_health;
    static QGraphicsTextItem *player_healthtext;
};

#endif // HEALTH_H
