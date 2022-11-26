#include "Enemy.hpp"
#include "GraphicManager.hpp"


Enemy::Enemy() :
    Character()
{
    damage = 1;
	jump = 0.0f;
}

const int Enemy::getDamage() const
{
    return damage;
}
void Enemy::setDamage(int d)
{
    damage = d;
}

void Enemy::checkIce()
{
    if (jump > 0.2f)
    {
        speed.y = -sqrtf(2 * GRAVITY * 130);
        jump -= 0.2f;
    } 
}
