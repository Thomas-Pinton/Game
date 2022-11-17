#pragma once

#include "Character.hpp"
#include "math.h"

class Player : public Character
{
private:
	bool canJump;
	int pontuation;
public:
	float movingSpeed;
	float mudCooldown;

	Player();
	void addPoints(int amount);
	const int getPoints() const;
	void checkKeys();
	//void displayPoints();
	virtual void execute();
	void setJump(bool p);

};
