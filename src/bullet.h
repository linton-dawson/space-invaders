#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>
#include<iostream>
#include<stdexcept>
#include<SFML/Audio.hpp>
#include<string>

class Bullet
{
public:

    Bullet(const int, float);

    sf::Sprite& getSprite();

    bool isAlive();

    void kill();

    void gen(bool);

    void position(float, float);

    void draw(sf::RenderWindow & );

private:

    sf::Sprite sprite;
    sf::Texture texture;
    bool alive;

};

#endif // BULLET_H
