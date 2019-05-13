#ifndef SHIP_H
#define SHIP_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Ship
{
public :

    Ship (float);

    sf::Sprite & getSprite();

    void position( float , float);

    void kill();

    void respawn();

    bool isAlive();

    //taking a window as an arg.
    void render(sf::RenderWindow &);

private:

    sf::Sprite sprite;

    sf::Texture texture;

    bool alive;
};

#endif
