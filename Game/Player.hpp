#pragma once

#include "Character.hpp"
#include "math.h"

class Player : public Character
{
private:
	bool canJump;
	int pontuation;
public:
	Player();

	void addPoints(int amount);
	void checkKeys();
	virtual void execute();
	void setJump(bool p);

};
