#include "oncollide.h"

using namespace std;

bool Oncollide::shipalien(Ship &ent1, Alien &ent2)
{
    sf::FloatRect ship;

    ship.left = ent1.getSprite().getGlobalBounds().left;
    ship.top = ent1.getSprite().getGlobalBounds().top;
    ship.width = ent1.getSprite().getGlobalBounds().width - 10;
    ship.height = ent1.getSprite().getGlobalBounds().height - 10;

    sf::FloatRect alien;

    alien.left = ent2.getSprite().getGlobalBounds().left;
    alien.width = ent2.getSprite().getGlobalBounds().width;
    alien.top = ent2.getSprite().getGlobalBounds().top;
    alien.height = ent2.getSprite().getGlobalBounds().height;

    return ship.intersects(alien);

}

bool Oncollide::alienbullet(Alien &ent1, Bullet &ent2)
{
    sf::FloatRect alien;

    alien.left = ent1.getSprite().getGlobalBounds().left;
    alien.width = ent1.getSprite().getGlobalBounds().width;
    alien.top = ent1.getSprite().getGlobalBounds().top;
    alien.height = ent1.getSprite().getGlobalBounds().height;

    sf::FloatRect bullet;

    bullet.left = ent2.getSprite().getGlobalBounds().left;
    bullet.width = ent2.getSprite().getGlobalBounds().width;
    bullet.top = ent2.getSprite().getGlobalBounds().top;
    bullet.height = ent2.getSprite().getGlobalBounds().height;

    return alien.intersects(bullet);
}
