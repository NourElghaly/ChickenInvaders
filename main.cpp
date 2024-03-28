#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <player.h>
#include <score.h>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene scene;
    scene.setSceneRect(0, 0, 800, 600);

    QGraphicsView view;
    view.setFixedSize(800, 600);


    QPixmap background(":/images/bakcground.jpg");
    scene.setBackgroundBrush(background.scaled(scene.width(),scene.height(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

    QGraphicsTextItem *score = new QGraphicsTextItem;
    score->setFont(QFont("times", 16));
    score->setDefaultTextColor(Qt::blue);
    score->setPlainText("Score: " + QString::number(0));
    score->setPos(600, 10);
    scene.addItem(score);



    QPixmap playericon(":/images/spaceship.jpg");
    playericon = playericon.scaledToWidth(100);
    playericon = playericon.scaledToHeight(100);
    // Setting up player
    Player*player= new Player;
    player->setPixmap(playericon);
    player->setFlag(QGraphicsItem::ItemIsFocusable);



    player->setFocus();
    player->setPos(view.width()/2,view.height()-playericon.height());
    scene.addItem(player);



    view.setScene(&scene);
    view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.show();

    return a.exec();
}
