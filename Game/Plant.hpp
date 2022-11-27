#pragma once

#include "Enemy.hpp"
#include "Player.hpp"
#include "Projectile.hpp"
#include <iostream>
#include <list>

namespace Enemies 
{
    class Plant :
        public Enemy
    {
    private:
        float shootCooldown;
        float shootInterval;
    public:
        std::list<Projectile*> projectiles;
        std::list<Projectile*>::iterator lastProjectileShooted;
        Plant();
        Plant(std::string line);
        ~Plant();
        std::list<Player*> players;
        void shoot(Player* pPlayer);
        void execute();
        void addProjectile(Projectile* pP);
        void setAlive(bool status);
        void save();
    };
}


