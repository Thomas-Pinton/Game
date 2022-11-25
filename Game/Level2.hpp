#pragma once

#include "Level.hpp"

class Level2 :
    public Level
{
private:
    Enemies::Pig* pPig;
public:
    Level2(Window* pW);
    void createPig(Coordinate<int> position, float changeDirectionTime = 1.5f + (rand() % 2) / 2);
    ~Level2();
};

