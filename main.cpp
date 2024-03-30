#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QApplication>
#include "health.h"
#include "player.h"
#include "points.h"
#include <QTimer>
#include <QMediaPlayer>
#include <QAudioOutput>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // Declaring view
    QGraphicsView view;
    view.setFixedSize(800, 600);
    // Declaring scene
    QGraphicsScene scene;
    scene.setSceneRect(0, 0, 800, 600);
    // Turning off scroll bar
    view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // Adding background
    QPixmap Background(":/images/bakcground.jpg");
    scene.setBackgroundBrush(Background.scaled(scene.width(), scene.height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    // Background music
    QMediaPlayer *mainplayer = new QMediaPlayer();
    if (!mainplayer->isPlaying())
    {
        mainplayer->play();
    }
    // Making player move
    player *player = new class player; // Assuming Player is the correct class name
    player->setPos(view.width() / 2, view.height() - 100);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    // Points
    Points *points = new Points(&scene);
    // Health
    health *health = new class health(&scene); // Assuming Health is the correct class name
    // Enemy spawning
    QTimer *time = new QTimer();
    QObject::connect(time, SIGNAL(timeout()), player, SLOT(generate()));
    time->start(1500);
    // The add part
    player->setFocus();
    scene.addItem(player);
    view.setScene(&scene);
    view.show();
    int result = a.exec();

    // Clean up dynamically allocated memory
    delete mainplayer;
    delete player;
    delete points;
    delete health;
    delete time;

    return result;
}
