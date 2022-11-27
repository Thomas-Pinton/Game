#pragma once

#include "Character.hpp"
#include "math.h"

class Player : public Character
{
private:
	bool canJump;
	bool canWalk;
	int pontuation;
	int playerId;
	int keys[3];
public:
	float movingSpeed;
	float mudCooldown;
	float sandCooldown;

	Player(int pId = 1);
	Player(std::string data);
	void addPoints(int amount);
	void assignKeys();
	const int getPoints() const;
	void checkKeys();
	//void displayPoints();
	void checkForObstacles();
	virtual void execute();
	void setJump(bool p);
	void setWalk(bool w);
	void executeJump(float height);
	void setHp(int newHp);
	void decreaseHp(int qtd);
	void save();

};
