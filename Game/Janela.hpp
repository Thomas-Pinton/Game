#pragma once

#include "SFML/Graphics.hpp"

class Janela
{
private:
	int HEIGHT;
	int WIDTH;
public:
	sf::RenderWindow config;
	Janela(int h = 720, int w = 1080)
	{
		HEIGHT = h, WIDTH = w;
		config.create(sf::VideoMode(WIDTH, HEIGHT), "Game");
	}
	const int getHEIGHT() const {
		return HEIGHT;
	}
	const int getWIDTH() const {
		return WIDTH;
	}
};

