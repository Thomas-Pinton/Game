#pragma once

#include "Obstacle.hpp"

namespace Obstacles
{
    class Ice :
        public Obstacle
    {
    private:
        float enemyJumpHeight;
    public:
        Ice();
        Ice(std::string data);
        void affectEnemy(Enemy* pE);
        void save();
    };
}



