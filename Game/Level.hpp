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
private:
	EntitiesList entities;
	ColisionManager colMan;
	GraphicManager grafMan;
public:
	Level(Window* window);
	~Level();
	void create(Window* window);
	virtual void execute(Window* w);
	void manageColisions(Window* window);
};

