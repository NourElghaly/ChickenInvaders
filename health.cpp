#include "health.h"
#include <QFont>
#include "score.h"
#include <QMessageBox>

health::health() : QObject(), player_health(3)
{
    health_text = new QGraphicsTextItem;
    health_text->setFont(QFont("times", 16));
    health_text->setDefaultTextColor(Qt::red);
    health_text->setPlainText("Health: " + QString::number(player_health));
    health_text->setPos(600, 50);

}

health::health(QGraphicsScene scene)
{
    scene.addItem(health_text);
}

void health::decrease()
{
    player_health--;
    health_text->setPlainText("HEALTH: " + QString::number(player_health));
    health_text->setDefaultTextColor(Qt::red);

    if (player_health == 0)
    {
        int scr = 0;
        Score score; // Create an instance of the Score class
        score.set_score(scr); // Call set_score function on the Score instance
        QMessageBox *box = new QMessageBox;
        box->setWindowTitle(QString("GAME OVER"));
        box->setText(QString("YOU LOSE... YOUR SCORE WAS: ") + QString::number(scr));
        box->setFixedHeight(800);
        box->setFixedWidth(800);
        box->exec();
        delete box; // Delete the message box after execution
        exit(0);
    }
}
