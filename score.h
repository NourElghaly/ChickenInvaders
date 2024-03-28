#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QObject>

class Score : public QObject
{
    Q_OBJECT

public:
    Score(QGraphicsScene scene);
    Score();

    void increase();
    void set_score(int& num);

    static int player_score;

private:
    QGraphicsTextItem* scoreText;
};

#endif // SCORE_H
