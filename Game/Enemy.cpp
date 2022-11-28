#include "Enemy.hpp"
#include "GraphicManager.hpp"
#include "Level.hpp"


Enemy::Enemy() :
    Character()
{
    damage = 1;
	jump = 0.0f;
}

Enemy::~Enemy()
{

}

const int Enemy::getDamage() const
{
    return damage;
}
void Enemy::setDamage(int d)
{
    damage = d;
}

void Enemy::setHp(int newHp)
{
    hp = newHp;
    if (hp <= 0)
    {
        pLevel->decreaseEnemyAmount();
        setAlive(false);
    }
}
void Enemy::decreaseHp(int qtd)
{
    hp -= qtd;
    if (hp <= 0)
    {
        pLevel->decreaseEnemyAmount();
        setAlive(false);
    }
}

void Enemy::checkIce()
{
    if (jump > 0.2f)
    {
        speed.y = jumpHeight;
        jump -= 0.2f;
    } 
}
