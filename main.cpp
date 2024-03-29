#include <QGraphicsview>
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
    view.setFixedSize(800, 800);
    // Declaring scene
    QGraphicsScene scene;
    scene.setSceneRect(0, 0, 800, 800);
    // Turning off scroll bar
    view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // Adding background
    QPixmap bgImage(":/images/bakcground.jpg");
    scene.setBackgroundBrush(bgImage.scaled(scene.width(), scene.height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    // Background music
    QAudioOutput *maintheme = new QAudioOutput();
    QMediaPlayer *mainplayer = new QMediaPlayer();
    maintheme->setVolume(70);
    mainplayer->setAudioOutput(maintheme);
    mainplayer->setSource(QUrl("qrc:/audios/background_music.mp3"));
    if (mainplayer->isPlaying())
    {
        mainplayer->setPosition(0);
    }
    else if (mainplayer->isPlaying() == QMediaPlayer::StoppedState)
    {
        mainplayer->play();
    }
    // Making player move
    player *player = new class player;
    player->setPos(view.width() / 2, view.height() - 100);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    // Points
    Points *points = new Points(&scene);
    // Health
    health *health = new class health(&scene);
    // Enemy spawning
    QTimer *time = new QTimer();
    QObject::connect(time, SIGNAL(timeout()), player, SLOT(spawn()));
    time->start(1500);
    // The add part
    player->setFocus();
    scene.addItem(player);
    view.setScene(&scene);
    view.show();
    return a.exec();
}
