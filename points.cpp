#include "points.h"
#include <QtGui/QFont>
#include <QtWidgets/QGraphicsScene>

int Points::playerPoints = 0;
QGraphicsTextItem *Points::playerPointsText = new QGraphicsTextItem;

Points::Points(QGraphicsScene *scene)
{
    // Setting up points display
    playerPointsText->setPlainText(QString("POINTS " + QString::number(playerPoints)));
    playerPointsText->setDefaultTextColor(QColorConstants::Svg::aqua);
    playerPointsText->setFont(QFont("script", 30));
    playerPointsText->setPos(5, 50);
    scene->addItem(playerPointsText);
}

void Points::increase()
{
    // Increasing points
    playerPoints += 100;
    playerPointsText->setPlainText(QString("POINTS: " + QString::number(playerPoints)));
    playerPointsText->setDefaultTextColor(QColorConstants::Svg::aqua);
    if (playerPoints < 0)
    {
        playerPointsText->setDefaultTextColor(Qt::red);
    }
}

void Points::decrease()
{
    // Decreasing points
    playerPoints -= 100;
    playerPointsText->setPlainText(QString("POINTS: " + QString::number(playerPoints)));
    playerPointsText->setDefaultTextColor(Qt::red);
}

void Points::setPoints(int &num)
{
    num = playerPoints;
}
