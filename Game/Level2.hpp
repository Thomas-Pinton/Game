#pragma once

#include "Sand.hpp"
#include "Ice.hpp"
#include "Level.hpp"

class Level2 :
    public Level
{
private:
    Enemies::Pig* pPig;
    Obstacles::Sand* pSand;
    Obstacles::Ice* pIce;
public:
    Level2(int playersAmount, bool loadFromSave);

    void loadEnemies();
    void loadObstacles();

    void createPig(Coordinate<int> position, float changeDirectionTime = 1.5f + (rand() % 2) / 2);
    void recoverPigs();

    void createMudObstacle(Coordinate<int> position);
    void recoverMuds();
    ~Level2();
};

