#include "health.h"
#include "QtWidgets/qgraphicsscene.h"
#include <QGraphicsTextItem>
#include <QGraphicsItem>
#include <QMessageBox>
#include "points.h"

int health::player_health = 3;
QGraphicsTextItem *health::player_healthtext = new QGraphicsTextItem;

health::health(QGraphicsScene *scene)
{
    // Displaying health on screen
    player_healthtext->setPlainText(QString("HEALTH " + QString::number(player_health)));
    player_healthtext->setDefaultTextColor(Qt::green);
    player_healthtext->setFont(QFont("Arial", 20));
    player_healthtext->setPos(10, 10);
    scene->addItem(player_healthtext);
}

void health::decrease()
{
    // Decreases health
    player_health--;
    points::decrease();
    player_healthtext->setPlainText(QString("HEALTH: " + QString::number(player_health)));
    player_healthtext->setDefaultTextColor(Qt::red);

    if (player_health == 0)
    {
        int sc = points::getPoints();
        QMessageBox *box = new QMessageBox;
        box->setWindowTitle(QString("GAME OVER"));
        box->setText(QString("YOU HAVE FAILED TO SAVE THE GALAXY. YOUR SCORE: ") + QString::number(sc));
        box->exec();
        exit(0);
    }
}
