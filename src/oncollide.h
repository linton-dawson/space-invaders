#ifndef ONCOLLIDE_H
#define ONCOLLIDE_H

#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<stdexcept>
#include "ship.h"
#include "alien.h"
#include "bullet.h"

class Oncollide
{
public:
    static bool shipalien(Ship& , Alien&);
    static bool alienbullet(Alien&, Bullet&);
};

#endif // ONCOLLIDE_H
