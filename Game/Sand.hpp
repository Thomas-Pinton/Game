#pragma once

#include "Obstacle.hpp"

namespace Obstacles
{
    class Sand :
        public Obstacle
    {
    private:
        float jumpHeightDecrease;
    public:
        Sand();
        void execute();
        void affectPlayer(Player* pP);
        //void save();
  
    };
}

