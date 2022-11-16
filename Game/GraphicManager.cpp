#include "GraphicManager.hpp"

namespace Manager {

	GraphicManager::GraphicManager()
	{
		pWindow = NULL;
		deltaTime = 0.0f;
	}

	GraphicManager::GraphicManager(Window* pW)
	{
		pWindow = pW;
		deltaTime = 0.0f;
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

	Window* GraphicManager::getWindow()
	{
		return pWindow;
	}

	float GraphicManager::updateDeltaTime()
	{
		deltaTime = (float)clock.restart().asSeconds();

		if (deltaTime > 0.15f)
			deltaTime = 0.15f;

		return deltaTime;
	}

	const float GraphicManager::getDeltaTime() const
	{
		return deltaTime;
	}

	void GraphicManager::printBeing(Being* pE)
	{
		pWindow->config.draw(pE->rectangle);
	}

	void GraphicManager::printText(sf::Text* pT)
	{
		pWindow->config.draw(*pT);
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

}