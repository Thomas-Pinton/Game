#pragma once

#include "Character.hpp"
#include "math.h"

class Player : public Character
{
private:
	bool canJump;
	int pontuation;
	int playerId;
public:
	float movingSpeed;
	float mudCooldown;

	Player(int pId = 1);
	void addPoints(int amount);
	const int getPoints() const;
	void checkKeys();
	//void displayPoints();
	virtual void execute();
	void setJump(bool p);

};
