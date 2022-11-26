#pragma once

#include "SFML/Graphics.hpp"
#include "Entity.hpp"
#include "Player.hpp"
#include "Enemy.hpp"

class Obstacle : public Entity
{
protected:
	float counterForce;
public:
	Obstacle();
	virtual void affectPlayer(Player* pP);
	virtual void affectEnemy(Enemy* pE);
	void execute();
};


