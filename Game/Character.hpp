#pragma once

#include "Entity.hpp"
#include "Constants.hpp"


class Character : public Entity
{
protected:
	int hp;
public:
	Character();
	const int getHp();
	void setHp(int novaVida);
	void decreaseHp(int qtd);
	void increaseHp(int qtd);
};
