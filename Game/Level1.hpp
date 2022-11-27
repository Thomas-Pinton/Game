#pragma once

#include "Level.hpp"

class Level1 :
    public Level
{
private:
    Enemies::Plant* pPlant;
    Projectile* pProjectile;
public:
    Level1(int playersAmount);
    void createPlant(Coordinate<int> position);
    Projectile* createProjectile();
    ~Level1();
};