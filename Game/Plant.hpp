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
        Player* pPlayer;
        void shoot();
        void execute();
        void addProjectile(Projectile* pP);
    };
}


