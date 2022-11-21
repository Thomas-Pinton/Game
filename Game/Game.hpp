#pragma once

#include "SFML/Graphics.hpp"
#include "Coordinate.hpp"
#include "Window.hpp"
#include "Level1.hpp"
#include "Level2.hpp"
#include "Menu.hpp"
#include "Plant.hpp"

#include <iostream>

class Game
{
private:
	Window window;
	GraphicManager* grapMan;
	Level1 level1;
	Level2 level2;
	Menu menu;
public:
	Game();
	~Game();
	void execute();
};
