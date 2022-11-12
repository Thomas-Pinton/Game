#pragma once

#include "Character.hpp"
#include "math.h"

class Player : public Character
{
private:
	bool canJump;
public:
	Player();

	void checkKeys();
	virtual void execute();
	void setJump(bool p);

};
