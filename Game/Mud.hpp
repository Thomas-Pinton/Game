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
        void execute();
    };
}



