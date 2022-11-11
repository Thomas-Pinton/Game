#include "GraphicManager.hpp"

GraphicManager::GraphicManager()
{
	pWindow = NULL;
}

GraphicManager::GraphicManager(Window* pW)
{
	pWindow = pW;
}

GraphicManager* GraphicManager::getInstance()
{
	if (GraphicManager::instance == NULL)
	{
		instance = new GraphicManager;
	}
	return instance;
}

void GraphicManager::setWindow(Window* pW)
{
	pWindow = pW;
}

void GraphicManager::printBeing(Being* pE)
{
	pWindow->config.draw(pE->rectangle);
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
	pWindow->config.clear();
}
void GraphicManager::display()
{
	pWindow->config.display();
}