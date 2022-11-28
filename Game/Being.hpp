#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "SFML/Graphics.hpp"
#include "Coordinate.hpp"
#include "StateManager.hpp"

namespace Manager {
	class GraphicManager;
}

// Tudo aquilo que tem representacao grafica
// Ex.: Character, blocos, menu, backgrounds, etc

enum classes {
	notSaved = -1,
	l1 = 1,
	l2 = 2,
	player,
	projectile,
	fireBlock,
	mud,
	flyingBlock,
	mushroom,
	plant,
	pig,
};

using namespace Manager;

class Being
{
protected:
	int id;
public:
	static Manager::GraphicManager* pGraMan;

	Being();
	
	~Being();

	virtual void execute() = 0;

	virtual void print() = 0;

	const int getId() const;

};



