#include "bullet.h"
#include<iostream>

using namespace std;

Bullet::Bullet (const int id, float speed)
{
    if(!texture.loadFromFile("bullet.png"))
        throw invalid_argument("Bullet sprite unavailable !");

    alive = false;

    sprite.setTexture(texture);
    sprite.scale(sf::Vector2f(0.1f,0.1f));
}

sf::Sprite& Bullet :: getSprite()
{
    return sprite;
}

void Bullet::position(float x, float y)
{
    sprite.setPosition(x,y);
}

void Bullet::kill()
{
    alive = false;
}

void Bullet::gen(bool status)
{
    alive = status;
}

void Bullet::draw(sf::RenderWindow &window)
{
    sprite.setTexture(texture);
    window.draw(sprite);
    //window.display();
}

bool Bullet::isAlive()
{
    return alive;
}
