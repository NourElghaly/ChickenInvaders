#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <Player.h>
#include <enemy.h>
#include <score.h>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene scene;
    scene.setSceneRect(0, 0, 800, 600);

    QGraphicsView view;
    view.setFixedSize(800, 600);
    view.setScene(&scene);
    view.show();

    view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    QPixmap background(":/images/background.jpg");
    scene.setBackgroundBrush(background.scaled(scene.width(),scene.height()));

    QGraphicsTextItem *score = new QGraphicsTextItem;
    score->setFont(QFont("times", 16));
    score->setDefaultTextColor(Qt::blue);
    score->setPlainText("Score: " + QString::number(0));
    score->setPos(600, 10);
    scene.addItem(score);

    // Creating and adding enemy to the scene
    QPixmap enemypix(":/images/chicken.jpg");
    enemypix = enemypix.scaledToWidth(200);
    enemypix = enemypix.scaledToHeight(200);
    QGraphicsPixmapItem *enemy = new QGraphicsPixmapItem;
    enemy->setPixmap(enemypix);
    scene.addItem(enemy);

    // Setting up player
    Player*player= new class Player;
    player->setPos(view.width()/2,view.height()-100);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    //score
    score * core= new class score(&scene);
    //health
    health* life=new health(&scene);
    //enemy spawning
    QTimer *time =new QTimer();
    QObject::connect(time,SIGNAL(timeout()),player,SLOT(spawn()));
    time->start(1500);

    player->setFocus();
    scene.addItem(player);
    view.setScene(&scene);
    view.show();

    return a.exec();
}
