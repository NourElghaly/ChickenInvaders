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
    player_healthtext->setPlainText(QString("HEALTH: " + QString::number(player_health)));
    player_healthtext->setDefaultTextColor(Qt::red);
    player_healthtext->setFont(QFont("times", 20));
    player_healthtext->setPos(600, 10);
    scene->addItem(player_healthtext);
}

void health::decrease()
{
    Points points;
    // Decreases health
    player_health--;
    player_healthtext->setPlainText(QString("HEALTH: " + QString::number(player_health)));

    if (player_health == 0)
    {
        int sc = points.getPoints();
        QMessageBox *box = new QMessageBox;
        box->setWindowTitle(QString("GAME OVER"));
        box->setText(QString("YOU LOOOOOSE...YOUR SCORE WAS: ") + QString::number(sc));
        box->exec();
        exit(0);
    }

    if(player_health<0)
    {
        player_healthtext->setPlainText(QString("HEALTH: " + QString::number(0)));
    }
}
