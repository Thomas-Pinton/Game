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
	virtual void setHp(int newHp);
	virtual void decreaseHp(int qtd);
	virtual void increaseHp(int qtd);
};
