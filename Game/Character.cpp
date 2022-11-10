#include "Character.hpp"

Character::Character()
	: Entity()
{
	hp = 100;
	// Todo personagem, por padr�o, sofre efeito da gravidade
	acceleration.y = 1000;
}

const int Character::getHp()
{
	return hp;
}

void Character::setHp(int novaVida)
{
	hp = novaVida;
}

void Character::decreaseHp(int qtd)
{
	hp -= qtd;
}

void Character::increaseHp(int qtd)
{
	hp += qtd;
}