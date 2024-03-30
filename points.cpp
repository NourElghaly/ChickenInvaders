#include "points.h"
#include <QtGui/QFont>
#include <QtWidgets/QGraphicsScene>

int Points::playerPoints = 0;
QGraphicsTextItem *Points::playerPointsText = new QGraphicsTextItem;

Points::Points(QGraphicsScene *scene)
{
    // Setting up points display

    scene->addItem(playerPointsText);
    Points();
}

Points::Points()

{
    playerPointsText->setPlainText(QString("POINTS: " + QString::number(playerPoints)));
    playerPointsText->setFont(QFont("times", 20 ));
    playerPointsText->setDefaultTextColor(Qt::blue);
    playerPointsText->setPos(600, 50);
}
void Points::increase()
{
    // Increasing points
    playerPoints += 100;
    playerPointsText->setPlainText(QString("POINTS: " + QString::number(playerPoints)));

}


void Points::setPoints(int &num)
{
    num = playerPoints;
}

int Points::getPoints()
{
    return playerPoints;
}
