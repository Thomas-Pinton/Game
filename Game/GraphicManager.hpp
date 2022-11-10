#pragma once

#include "Window.hpp"
#include "Being.hpp"

class GraphicManager
{
private:
	Window* window;
public:
	void setWindow(Window* pW);
	GraphicManager();

	//void print();
	void printBeing(Being* pE);
	//void imprimeLista(std::list<Being*> l);
	//void imprimeLista(std::list<Entity*> l);
	//void imprimeLista(std::list<Player*> l);

	void clear();
	void display();
};