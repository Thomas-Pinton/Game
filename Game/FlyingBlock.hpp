#pragma once

#include "Obstacle.hpp"

namespace Obstacles 
{
    class FlyingBlock :
        public Obstacle
    {
    public:
        FlyingBlock();
        void affectPlayer();
        void save();
    };
}



