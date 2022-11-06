#pragma once

#include "SFML/Graphics.hpp"
#include "Coordinate.hpp"
#include "Window.hpp"
#include "Level.hpp"

#include <iostream>

class Game
{
private:
	Window window;
	Level level1;
public:
	Game();
	void execute();
};
