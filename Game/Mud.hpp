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
        Mud(std::string data);
        void execute();
        void affectPlayer(Player* pP);
        void save();
    };
}



