#pragma once

#include "SFML/Graphics.hpp"
#include "Coordinate.hpp"
#include "Window.hpp"
#include "Level1.hpp"
#include "Level2.hpp"
#include "Menu.hpp"
#include "Plant.hpp"
#include "StateManager.hpp"

#include <iostream>

class Game
{
private:
	Window window;
	GraphicManager* grapMan;
	StateManager* pStateMan;
public:
	Game();
	~Game();
	void execute();
};
