#include "player.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "enemy.h"
#include "bullet.h"

Player::Player(QObject *parent) : QObject(parent), QGraphicsPixmapItem()
{
    player_health = 3;
    player_score = 0;
    time = new QTimer(this);
    QObject::connect(time, SIGNAL(timeout()), this, SLOT(create_enemy()));
    time->start(2000);

    // Create text items for score and health
    health_text = new QGraphicsTextItem();
    health_text->setPlainText("Health: " + QString::number(player_health));
    health_text->setDefaultTextColor(Qt::red);
    health_text->setPos(10, 10); // Adjust position as needed
    scene()->addItem(health_text); // Add health text to the scene

    score_text = new QGraphicsTextItem();
    score_text->setPlainText("Score: " + QString::number(player_score));
    score_text->setDefaultTextColor(Qt::blue);
    score_text->setPos(10, 30); // Adjust position as needed
    scene()->addItem(score_text); // Add score text to the scene
}

void Player::keyPressEvent(QKeyEvent *event)
{
    // Player movement
    if (event->key() == Qt::Key_Left)
    {
        if (pos().x() > 9)
            setPos(x() - 30, y());
    }
    else if (event->key() == Qt::Key_Right)
    {
        if (pos().x() + 70 < 800)
            setPos(x() + 30, y());
    }
    else if (event->key() == Qt::Key_Up)
    {
        if (pos().y() != 0)
            setPos(x(), y() - 20);
    }
    else if (event->key() == Qt::Key_Down)
    {
        // Ensure player doesn't go below the screen
        if (pos().y() + 20 < 600) // Check against the height of the view
            setPos(x(), y() + 20);
    }
    else if(event->key() == Qt::Key_Space)
    {
        Bullet *bullet = new Bullet(); // Create a new bullet
        bullet->setPos(x() + 35, y() - 65); // Adjust bullet position
        scene()->addItem(bullet); // Add bullet to the scene
    }
}

void Player::up_score()
{
    player_score++;
    score_text->setPlainText("Score: " + QString::number(player_score));
}

void Player::down_health()
{
    player_health--;
    health_text->setPlainText("Health: " + QString::number(player_health));
    if(player_health <= 0)
    {
        // Handle game over condition
    }
}

int Player::get_health()
{
    return player_health;
}

void Player::create_enemy()
{
    Enemy *enemy = new Enemy(); // Create a new enemy
    scene()->addItem(enemy); // Add enemy to the scene
}
