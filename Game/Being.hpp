#pragma once

#include <iostream>
#include <string>
#include "SFML/Graphics.hpp"
#include "Coordinate.hpp"

namespace Manager {
	class GraphicManager;
}


// Tudo aquilo que tem representa��o gr�fica
// Ex.: Character, blocos, menu, backgrounds, etc

using namespace Manager;

class Being
{
protected:
	static int id_count;
	int id;
public:
	static Manager::GraphicManager* pGraMan;

	Being();

	virtual void print() = 0;

	const int getId() const;

};



