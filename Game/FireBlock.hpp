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
        FireBlock(std::string data);
        ~FireBlock();
        void affectPlayer(Player* pP);
        void save();
    };
}



