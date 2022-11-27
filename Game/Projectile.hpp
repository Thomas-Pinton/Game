#pragma once

#include "Entity.hpp"

class Projectile :
    public Entity
{
private:
    int damage;
public:
    Projectile();
    Projectile(std::string data);
    const int getDamage() const;
    void setDamage(int d);
    void reset(Coordinate<float> pos);
    void save();
};

