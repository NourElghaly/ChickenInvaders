#ifndef POINTS_H
#define POINTS_H

#include <QGraphicsTextItem>
#include <QGraphicsScene>

class Points
{
public:
    Points(QGraphicsScene *scene);
    Points();
    static void increase();
    static void setPoints(int &num);
    int getPoints();

private:
    static int playerPoints;
    static QGraphicsTextItem *playerPointsText;
};

#endif // POINTS_H
