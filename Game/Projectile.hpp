#pragma once

#include "Entity.hpp"

class Projectile :
    public Entity
{
private:
    int damage;
public:
    Projectile();
    const int getDamage() const;
    void setDamage(int d);
    void reset(Coordinate<float> pos);
};

