#pragma once

#include <iostream>
#include "List.hpp"
#include "EntitiesList.hpp"
#include "GraphicManager.hpp"
#include "ColisionManager.hpp"
#include "Player.hpp"
#include "Obstacle.hpp"
#include "Enemy.hpp"

using namespace Manager;

class Level : public Being
{
protected:
	EntitiesList entities;
	Window* pWindow;
	ColisionManager colMan;
	Manager::GraphicManager* pGraMan;
	int* tileMap;
public:
	Level(Window* pW, Manager::GraphicManager* pGM);
	~Level();
	virtual void execute() = 0;
	void manageColisions();
};

