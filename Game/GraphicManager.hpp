#pragma once

#include "Window.hpp"
#include "Being.hpp"

class GraphicManager
{
private:
	Window* pWindow;
public:

	GraphicManager();
	GraphicManager(Window* pW);

	void setWindow(Window* pW);

	//void print();
	void printBeing(Being* pE);
	//void imprimeLista(std::list<Being*> l);
	//void imprimeLista(std::list<Entity*> l);
	//void imprimeLista(std::list<Player*> l);

	void clear();
	void display();
};