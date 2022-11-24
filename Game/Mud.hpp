#pragma once

#include "Obstacle.hpp"

namespace Obstacles 
{
    class Mud :
        public Obstacle
    {
    private:
        float slowdown;
    public:
        Mud();
        void execute();
        void affectPlayer(Player* pP);
        void save();
    };
}



