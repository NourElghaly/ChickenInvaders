#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsTextItem>
#include<QGraphicsItem>
class score
{
public:
    score(QGraphicsScene * scene);
    static void increase();
    static void deacrease();
    static void set_score(int &num);
private:
    static int player_score;
    static QGraphicsTextItem * player_scoretext;
};

#endif // SCORE_H
