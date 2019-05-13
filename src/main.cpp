#include <iostream>
#include "alien.h"
#include "ship.h"
#include "oncollide.h"
#include "bullet.h"

#define WIDTH 800
#define HEIGHT 600
#define ALIEN_NUM 10

using namespace std;

int main()
{
    const float shipSpeed = 200.0f;
    const int alienSpeedU = 1000;
    const int alienSpeedL = 100;
    const float bulletSpeed = 10.0f;
    bool GameOver = false;
    bool gameWin = false;

    sf::RenderWindow mainwindow (sf::VideoMode(WIDTH, HEIGHT), "Space Invaders");
    mainwindow.setFramerateLimit(60);
    mainwindow.setVerticalSyncEnabled(true);

    Bullet bullet(0,bulletSpeed); //is bulletID necessary ?

    Ship player(shipSpeed);
    player.position(WIDTH/2, HEIGHT - player.getSprite().getGlobalBounds().height/2 - 30);

    sf::Sprite background;
    sf::Texture starry;

    if(!starry.loadFromFile("star.png"))
        throw invalid_argument("Background not loaded !");

    background.setTexture(starry);

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
                if(event.type == sf::Event::Closed)
                    mainwindow.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) ) {
            if(player.getSprite().getPosition().x > 0.f)
                player.getSprite().move(-shipSpeed * time, 0.f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) ) {
            if(player.getSprite().getPosition().x + player.getSprite().getGlobalBounds().width < WIDTH)
                player.getSprite().move(shipSpeed * time, 0.0f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) ) {
            if(player.getSprite().getPosition().y > 0.f)
                player.getSprite().move(0.f, -shipSpeed * time);
        }

        if (sf::Keyboard::isKeyPressed (sf::Keyboard::S) ) {
            if(player.getSprite().getPosition().y < HEIGHT)
                player.getSprite().move(0.f, shipSpeed * time);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            bullet.gen(true);
            if(bullet.isAlive() && !GameOver)
            {
                bullet.position(player.getSprite().getPosition().x + 23 , player.getSprite().getPosition().y - 10);
                //bullet.draw(mainwindow);
            }
        }

        sf::Time altime = alienClock.getElapsedTime();

        if(altime.asSeconds() > 5.0f)
        {
            for(auto i =0;i < ALIEN_NUM ; i++)
            {
                enemy[i].getSprite().move(0.f, enemy[i].getSpeed() * time);
            }
            alienClock.restart();
        }

        sf::Time bultime = bulletClock.getElapsedTime();

        if(bultime.asSeconds() > .05f)
        {
            if(bullet.isAlive() && !GameOver)
            {
                bullet.draw(mainwindow);
                bullet.getSprite().move(0,-20);
            }
            bulletClock.restart();
        }
// alien and screen bottom
        for( auto i = 0; i < ALIEN_NUM ; i++)
        {
            if(enemy[i].getSprite().getPosition().y < 0)
            {
                GameOver = true;
                gameWin = false;
                cout<<"LOST\n";
            }
        }

// alien and bullet
        for( auto i = 0 ; i< ALIEN_NUM; i++)
        {
            if(Oncollide::alienbullet(enemy[i], bullet) && enemy[i].isAlive())
            {
                enemy[i].kill();
                bullet.kill();
            }
        }


        if(!GameOver)
        {
            for(int i = 0 ; i < ALIEN_NUM; i++)
            {
                if(enemy[i].isAlive())
                    enemy[i].draw(mainwindow);
            }

            if(player.isAlive())
                player.render(mainwindow);
        }
 //       mainwindow.clear(sf::Color::White);
        mainwindow.draw(background);
        mainwindow.display();
    }

    return EXIT_SUCCESS;
}
