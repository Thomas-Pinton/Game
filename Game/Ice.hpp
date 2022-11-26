#pragma once

#include "Obstacle.hpp"

namespace Obstacles
{
    class Ice :
        public Obstacle
    {
    private:
        float enemySpeedBoost;
    public:
        Ice();
        void affectEnemy(Enemy* pE);
    };
}



