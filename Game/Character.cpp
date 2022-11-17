#include "Character.hpp"

Character::Character()
	: Entity()
{
	hp = 1;
	// Todo personagem, por padr�o, sofre efeito da gravidade
	acceleration.y = GRAVITY;
}

const int Character::getHp()
{
	return hp;
}

void Character::setHp(int novaVida)
{
	hp = novaVida;
	if (hp <= 0)
		alive = false;
}

void Character::decreaseHp(int qtd)
{
	hp -= qtd;
	if (hp <= 0)
		alive = false;
}

void Character::increaseHp(int qtd)
{
	hp += qtd;
}