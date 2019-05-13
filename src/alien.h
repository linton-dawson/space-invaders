#pragma once

#include <SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<iostream>
#include<stdexcept>
#include<string>

class Alien
{

public:

    Alien() {}
    Alien(const int, float);

    sf::Sprite& getSprite();

    void position (float , float);

    void kill();

    bool isAlive();

    float getSpeed();

    void draw(sf::RenderWindow &);

private:

    sf::Sprite sprite;

    sf::Texture texture;

    bool alive;

    float speed;
};
