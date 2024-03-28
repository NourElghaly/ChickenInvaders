#include "score.h"
#include <QFont>

int Score::player_score = 0;

Score::Score() : QObject()
{
    scoreText = new QGraphicsTextItem;
    scoreText->setFont(QFont("times", 16));
    scoreText->setDefaultTextColor(Qt::blue);
    scoreText->setPlainText("Score: " + QString::number(player_score));
    scoreText->setPos(600, 10);

}

Score::Score(QGraphicsScene scene)
{
    scene.addItem(scoreText);
}

void Score::increase()
{
    player_score += 10;
    scoreText->setPlainText("Score: " + QString::number(player_score));
}

void Score::set_score(int& num)
{
    player_score = num;
}

