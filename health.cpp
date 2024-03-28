#include "health.h"
#include "QtWidgets/qgraphicsscene.h"
#include <QGraphicsTextItem>
#include<QGraphicsItem>
#include <QMessageBox>
#include "score.h"
int health::player_health=3;
QGraphicsTextItem *health::player_healthtext=new QGraphicsTextItem;
health::health(QGraphicsScene * scene)
{
    //putting health on screen
    player_healthtext->setPlainText(QString("HEALTH " + QString::number(player_health)));
    player_healthtext->setDefaultTextColor(Qt::green);
    player_healthtext->setFont(QFont("script", 30));
    player_healthtext->setPos(5,90);
    scene->addItem(player_healthtext);
}

void health::decrease()
{
    //decreases health
    player_health--;
    score::deacrease();
    player_healthtext->setPlainText(QString("HEALTH: " + QString::number(player_health)));
    player_healthtext->setDefaultTextColor(Qt::red);
    if(player_health==0)
    {
        int sc = 0;
        score::set_score(sc);
        QMessageBox *box=new QMessageBox;
        box->setWindowTitle(QString("GAMER OVER"));
        box->setText(QString("YOU HAVE FAILED TO SAVE THE GALAXY, YOUR SCORE WAS: ")+QString::number(sc));
        box->setFixedHeight(800);
        box->setFixedWidth(800);
        box->exec();
        exit(0);
    }
}
