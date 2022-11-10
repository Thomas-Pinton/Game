#include "GraphicManager.hpp"

GraphicManager::GraphicManager()
{
	window = NULL;
}

void GraphicManager::setWindow(Window* pW)
{
	window = pW;
}

void GraphicManager::printBeing(Being* pE)
{
	window->config.draw(pE->rectangle);
}
/*
void GraphicManager::print() 
{
	// Clear screen
	window->config.clear();

	imprimeLista(staticEntities);
	imprimeLista(movingEntities);
	imprimeLista(players);

	window->config.display();
}

// posso criar uma lista minha, com template, que tem uma fun��o print lista

void GraphicManager::imprimeLista(std::list<Being*> l)
{
	std::list <Being*>::iterator i;

	for (i = l.begin(); i != l.end(); i++) {
		window->config.draw((*i)->rectangle);
	}
}

void GraphicManager::imprimeLista(std::list<Entity*> l)
{
	std::list <Entity*>::iterator i;

	for (i = l.begin(); i != l.end(); i++) {
		window->config.draw((*i)->rectangle);
	}
}

void GraphicManager::imprimeLista(std::list<Player*> l)
{
	std::list <Player*>::iterator i;

	for (i = l.begin(); i != l.end(); i++) {
		window->config.draw((*i)->rectangle);
	}
}
*/
void GraphicManager::clear()
{
	window->config.clear();
}
void GraphicManager::display()
{
	window->config.display();
}