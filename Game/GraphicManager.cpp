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

		if (deltaTime > 0.05f)
		{
			std::cout << "Too big of a delta time " << std::endl;
			deltaTime = 0.05f;
		}
		return deltaTime;
	}

	const float GraphicManager::getDeltaTime() const
	{
		return deltaTime;
	}

	void GraphicManager::printEntity(Entity* pE)
	{
		pWindow->config.draw(pE->rectangle);
	}

	void GraphicManager::printText(sf::Text* pT)
	{
		pWindow->config.draw(*pT);
	}

	void GraphicManager::clear()
	{
		pWindow->config.clear();
	}

	void GraphicManager::display()
	{
		pWindow->config.display();
	}

}