#include "Window.hpp"

Janela::Janela(int h = 720, int w = 1080)
{
	HEIGHT = h, WIDTH = w;
	config.create(sf::VideoMode(WIDTH, HEIGHT), "Game");
}
const int Janela::getHEIGHT() const {
	return HEIGHT;
}
const int Janela::getWIDTH() const {
	return WIDTH;
}