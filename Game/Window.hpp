#pragma once

#include "SFML/Graphics.hpp"

class Window
{
private:
	int HEIGHT;
	int WIDTH;
public:
	sf::RenderWindow config;

	Window(int h, int w);

	const int getHEIGHT() const;

	const int getWIDTH() const;

};
