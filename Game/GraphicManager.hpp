#pragma once

#include "Window.hpp"
#include "Being.hpp"

class GraphicManager
{
private:
	Window* pWindow;
	GraphicManager();
	GraphicManager(Window* pW);
	float deltaTime;
	sf::Clock clock;

	static GraphicManager* instance;

public:

	static GraphicManager* getInstance();

	void setWindow(Window* pW);

	float updateDeltaTime();

	const float getDeltaTime() const;

	//void print();
	void printBeing(Being* pE);
	//void imprimeLista(std::list<Being*> l);
	//void imprimeLista(std::list<Entity*> l);
	//void imprimeLista(std::list<Player*> l);

	void clear();
	void display();
};