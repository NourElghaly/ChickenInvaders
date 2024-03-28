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

    QGraphicsView view(&scene); // Pass scene to view
    view.setFixedSize(800, 600);

    // Set up player
    Player *player = new Player(&scene); // Pass scene to player constructor
    player->setPixmap(QPixmap(":/images/spaceship.png").scaled(100, 100));
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    player->setPos(view.width() / 2, view.height() - player->pixmap().height());
    scene.addItem(player);

    QPixmap background(":/images/bakcground.jpg");
    scene.setBackgroundBrush(background.scaled(scene.width(), scene.height()));

    view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.show();

    return a.exec();
}
