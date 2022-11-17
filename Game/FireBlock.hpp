#pragma once

#include "Obstacle.hpp"

namespace Obstacles 
{
    class FireBlock :
        public Obstacle
    {
    private:
        int damage;
    public:
        FireBlock();
        void affectPlayer(Player* pP);
    };
}



