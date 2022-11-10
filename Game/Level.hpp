#pragma once

#include <iostream>
#include "List.hpp"
#include "EntitiesList.hpp"
#include "GraphicManager.hpp"
#include "ColisionManager.hpp"
#include "Player.hpp"
#include "Tile.hpp"
#include "Enemy.hpp"

class Level : public Being
{
protected:
	EntitiesList entities;
	Window* pWindow;
	ColisionManager colMan;
	GraphicManager* pGraMan;
public:
	Level(Window* pW, GraphicManager* pGM);
	~Level();
	virtual void execute() = 0;
	void manageColisions();
};

