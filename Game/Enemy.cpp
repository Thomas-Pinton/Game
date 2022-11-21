#include "Enemy.hpp"


Enemy::Enemy() :
    Character()
{
    damage = 1;
}

const int Enemy::getDamage() const
{
    return damage;
}
void Enemy::setDamage(int d)
{
    damage = d;
}