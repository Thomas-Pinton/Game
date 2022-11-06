#include "Window.hpp"

Window::Window(int h = 720, int w = 1080)
{
	HEIGHT = h, WIDTH = w;
	config.create(sf::VideoMode(WIDTH, HEIGHT), "Game");
}
const int Window::getHEIGHT() const {
	return HEIGHT;
}
const int Window::getWIDTH() const {
	return WIDTH;
}