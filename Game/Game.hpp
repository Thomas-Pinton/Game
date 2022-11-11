#pragma once

#include "SFML/Graphics.hpp"
#include "Coordinate.hpp"
#include "Window.hpp"
#include "Level1.hpp"

#include <iostream>

class Game
{
private:
	Window window;
	GraphicManager* grapMan;
	Level1 level1;
public:
	Game();
	~Game();
	void execute();
};
