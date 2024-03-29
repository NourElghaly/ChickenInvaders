#include "points.h"
#include <QtGui/QFont>
#include <QtWidgets/QGraphicsScene>

int Points::playerPoints = 0;
QGraphicsTextItem *Points::playerPointsText = new QGraphicsTextItem;

Points::Points(QGraphicsScene *scene)
{
    // Setting up points display

    scene->addItem(playerPointsText);
}

Points::Points()

{
    playerPointsText->setPlainText(QString("POINTS " + QString::number(playerPoints)));
    playerPointsText->setDefaultTextColor(Qt::blue);
    playerPointsText->setFont(QFont("times", 30));
    playerPointsText->setPos(10, 10);
}
void Points::increase()
{
    // Increasing points
    playerPoints += 100;
    playerPointsText->setPlainText(QString("POINTS: " + QString::number(playerPoints)));
    playerPointsText->setDefaultTextColor(Qt::blue);
    if (playerPoints < 0)
    {
        playerPointsText->setDefaultTextColor(Qt::blue);
    }
}



void Points::setPoints(int &num)
{
    num = playerPoints;
}

int Points::getPoints()
{
    return playerPoints;
}
