#include <iostream>
#include "alien.h"
#include "ship.h"
#include "oncollide.h"
#include "bullet.h"

#define WIDTH 800
#define HEIGHT 600
#define ALIEN_NUM 7

using namespace std;

int main()
{
    const float shipSpeed = 400.0f;
    const int alienSpeedU = 1200;
    const int alienSpeedL = 500;
    const float bulletSpeed = 600.0f;
    bool GameOver = false;
    bool gameWin = false;

    sf::RenderWindow mainwindow (sf::VideoMode(WIDTH, HEIGHT), "Space Invaders");
    mainwindow.setVerticalSyncEnabled(true);

    Bullet bullet(0,bulletSpeed); //is bulletID necessary ?

    Ship player(shipSpeed);
    player.position(WIDTH/2, HEIGHT - player.getSprite().getGlobalBounds().height/2);

    Alien enemy[ALIEN_NUM];
    for(int i=0; i<ALIEN_NUM; i++)
    {
        Alien singleEnemy(i , alienSpeedL + (rand()%alienSpeedU));
        singleEnemy.position(i*100+50 , singleEnemy.getSprite().getGlobalBounds().height/2);
        enemy[i] = singleEnemy;
    }

    sf::Clock mainClock, alienClock, bulletClock;

    alienClock.restart().asSeconds();
    bulletClock.restart().asSeconds();

    while(mainwindow.isOpen())
    {
        float time = mainClock.restart().asSeconds();

        sf::Event event;

        while(mainwindow.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed :
                    mainwindow.close();
                    break;
                    
                case (sf::Event::KeyPressed && event.key.code == sf::Keyboard::A
            }
        }
    }

    return 0;
}
