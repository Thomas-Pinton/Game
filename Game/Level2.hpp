#pragma once

#include "Ice.hpp"
#include "Level.hpp"


class Level2 :
    public Level
{
private:
    Enemies::Pig* pPig;
    Obstacles::Mud* pMud;
public:
    Level2(int playersAmount, bool loadFromSave);
    ~Level2();

    void loadEnemies();
    void loadObstacles();

    void createPig(Coordinate<int> position, float changeDirectionTime = 1.5f + (rand() % 2) / 2);
    void recoverPigs();

    void createMudObstacle(Coordinate<int> position);
    void recoverMuds();
};


