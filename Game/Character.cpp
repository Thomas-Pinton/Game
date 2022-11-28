#include "Character.hpp"

Character::Character()
	: Entity()
{
	hp = 1;
	// Todo personagem, por padr�o, sofre efeito da gravidade
	acceleration.y = GRAVITY;
	jumpHeight = 0;
}

const int Character::getHp() const
{
	return hp;
}

void Character::setHp(const int newHp)
{
	hp = newHp;
	if (hp <= 0)
		setAlive(false);
}

void Character::decreaseHp(const int qtd)
{
	hp -= qtd;
	if (hp <= 0)
		setAlive(false);
}

void Character::increaseHp(int qtd)
{
	hp += qtd;
}

void Character::setJumpHeight(float jH)
{
	jumpHeight = jH;
}

float Character::getJumpHeight()
{
	return jumpHeight;
}