#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsScene>
#include <QGraphicsTextItem>

class health: public QObject

{
    Q_OBJECT

public:
    health();
    health(QGraphicsScene scene); // Modified constructor to take a pointer to QGraphicsScene
    void decrease(); // Removed static keyword from member function

private:
    int player_health; // Removed static keyword from member variable
    QGraphicsTextItem* health_text; // Removed static keyword from member variable
};

#endif // HEALTH_H
