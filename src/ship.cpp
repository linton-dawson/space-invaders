#include "ship.h"
#include<iostream>
#include <stdexcept>

using namespace std;

Ship::Ship (float speed)
{
    alive = true;
    if(!texture.loadFromFile("shipalive.png")) {
        throw invalid_argument("Ship sprite unavailable !");
    }

    sprite.setTexture(texture);
    sprite.scale(sf::Vector2f(0.2f,0.2f));

}

void Ship :: position(float x, float y)
{
    sprite.setPosition(x,y);
}

sf::Sprite& Ship::getSprite()
{
    return sprite;
}

void Ship::kill()
{
    alive = false;
}

bool Ship::isAlive()
{
    return alive;
}

void Ship::respawn()
{
    alive = true;
}

void Ship::render(sf::RenderWindow &window)
{
    sprite.setTexture(texture);
    window.draw(sprite);
    window.display();
}
