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
    ~Level1();

    void createPlant(Coordinate<int> position);
    Projectile* createProjectile();

    void recoverPlants();
    Projectile* recoverProjectile(int projectilePosition);
};