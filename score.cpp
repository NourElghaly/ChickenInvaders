#include "score.h"
#include "QtGui/qfont.h"
#include "QtWidgets/qgraphicsscene.h"
#include <QGraphicsTextItem>
#include<QGraphicsItem>
int score::player_score=0;
QGraphicsTextItem *score::player_scoretext=new QGraphicsTextItem;
score::score(QGraphicsScene * scene)
{
    //putting score on ui
    player_scoretext->setPlainText(QString("SCORE " + QString::number(player_score)));
    player_scoretext->setDefaultTextColor(QColorConstants::Svg::aqua);
    player_scoretext->setFont(QFont("script", 30));
    player_scoretext->setPos(5,50);
    scene->addItem(player_scoretext);
}

void score::increase()
{
    //increasing score
    player_score=player_score+100;
    player_scoretext->setPlainText(QString("SCORE: " + QString::number(player_score)));
    player_scoretext->setDefaultTextColor(QColorConstants::Svg::aqua);
    if(player_score<0)
    {
        player_scoretext->setDefaultTextColor(Qt::red);
    }
}

void score::deacrease()
{
    //decreasing score
    player_score=player_score-100;
    player_scoretext->setPlainText(QString("SCORE: " + QString::number(player_score)));
    player_scoretext->setDefaultTextColor(Qt::red);
}

void score::set_score(int &num)
{
    num=player_score;
}
