#pragma once

#include "Enemy.hpp"

namespace Enemies
{
    class Mushroom :
        public Enemy
    {
    private:
        float changeDirectionTime;
        float timeElapsed;
    public:
        Mushroom(float chDirTime = 4);
        void execute();
    };
}



