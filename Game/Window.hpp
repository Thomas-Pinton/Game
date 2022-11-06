#pragma once

#include "SFML/Graphics.hpp"

class Janela
{
private:
	int HEIGHT;
	int WIDTH;
public:
	sf::RenderWindow config;

	Janela(int h, int w);

	const int getHEIGHT() const;

	const int getWIDTH() const;

};
