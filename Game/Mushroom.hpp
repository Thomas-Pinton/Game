#pragma once

#include "Enemy.hpp"

class Mushroom :
    public Enemy
{
private:
    float changeDirectionTime;
    float timeElapsed;
public:
    Mushroom(float chDirTime);
    void execute();
};

