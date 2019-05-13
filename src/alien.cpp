#include "alien.h"

using namespace std;

Alien :: Alien(const int aID, float spd)
{
    if(!texture.loadFromFile("alienalive.png"))
        throw invalid_argument("Alien sprite not available !");

    sprite.setTexture(texture);
    sprite.scale(sf::Vector2f(0.2f,0.2f));
    speed = spd;
}

void Alien :: position(float x, float y)
{
    sprite.setPosition(x,y);
}

void Alien :: kill()
{
    alive = false;
}

bool Alien :: isAlive()
{
    return alive;
}

float Alien :: getSpeed()
{
    return speed;
}

void Alien :: draw(sf::RenderWindow &window)
{
    sprite.setTexture(texture);
    window.draw(sprite);
    window.display();
}

sf::Sprite& Alien::getSprite()
{
    return sprite;
}
