#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "SFML/Graphics.hpp"
#include "Coordinate.hpp"

namespace Manager {
	class GraphicManager;
}

// Tudo aquilo que tem representa��o gr�fica
// Ex.: Character, blocos, menu, backgrounds, etc

enum classes {
	notSaved = -1,
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

	virtual void print() = 0;

	const int getId() const;

};



