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

	GraphicManager::~GraphicManager()
	{
		for (std::map<std::string, sf::Texture*>::iterator paths = textureMap.begin(); paths != textureMap.end(); paths++)
		{
			delete (*paths).second;
		}
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

	sf::Texture* GraphicManager::loadTexture(std::string filePath)
	{
		for (std::map<std::string, sf::Texture*>::iterator paths = textureMap.begin(); paths != textureMap.end(); paths++)
		{
			if ((*paths).first == filePath)
			{
				return (*paths).second;
			}
		}

		std::cout << "Texture in " << filePath << "Not loaded yet." << std::endl;


		sf::Texture* text = new sf::Texture();
		if (!text->loadFromFile("../Assets/" + filePath))
		//if (!text->loadFromFile(filePath))
			std::cout << "Error loading new texture " << std::endl;

		textureMap.insert({ filePath, text });

		std::cout << "Texture loaded" << std::endl;

		return text;
			
	}
}