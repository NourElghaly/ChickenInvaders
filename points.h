#ifndef POINTS_H
#define POINTS_H

#include <QGraphicsTextItem>
#include <QGraphicsScene>

class Points
{
public:
    Points(QGraphicsScene *scene);
    static void increase();
    static void decrease();
    static void setPoints(int &num);

private:
    static int playerPoints;
    static QGraphicsTextItem *playerPointsText;
};

#endif // POINTS_H
