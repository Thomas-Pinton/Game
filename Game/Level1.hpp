#pragma once

#include "Level.hpp"
#include "Ice.hpp"

class Level1 :
    public Level
{
private:
    Enemies::Plant* pPlant;
    Projectile* pProjectile;
    Obstacles::Ice* pIce;
public:
    Level1(int playersAmount, bool loadFromSave);
    ~Level1();

    void createEnemies();
    void loadEnemies();
    void loadObstacles();

    void createPlant(Coordinate<int> position);
    Projectile* createProjectile();
    void createIceObstacle(Coordinate<int> position);

    void recoverPlants();
    Projectile* recoverProjectile(int projectilePosition);
    void recoverIce();
};