#pragma once

#include "SFML/Graphics.hpp"
#include "Entity.hpp"
#include "Player.hpp"

class Obstacle : public Entity
{
private:
	float counterForce;
public:
	virtual void affectPlayer(Player* pP);
};


