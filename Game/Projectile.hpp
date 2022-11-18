#pragma once

#include "Entity.hpp"

class Projectile :
    public Entity
{
private:
    int damage;
public:
    Projectile();
};

